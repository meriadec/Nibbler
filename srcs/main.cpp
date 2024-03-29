#include <nibbler.hpp>
#include <IGraphic.hpp>
#include <Rolex.hpp>
#include <GeorgeRRMartin.hpp>
#include <Kasparov.hpp>
#include <string.h>

static void switchGraphic (std::string lib, IGraphic ** g, GeorgeRRMartin & got)
{
    if (got.setGraphic(lib)) {
        *g = got.getGraphic();
        (*g)->start();
    }
}

int main (int ac, char ** av)
{
    if (ac < 3 || ac > 5) {
        std::cerr << "You should launch this program like: ./nibbler <width> <height> [players] [finite]" << std::endl;
        return (42);
    }

    int w = std::atoi(av[1]);
    int h = std::atoi(av[2]);
    bool isFinite = false;
    int nbPlayers = ac >= 4 ? std::atoi(av[3]) : 1;

    if (w < 50 || w > 100 || h < 50 || h > 100 || nbPlayers < 1 || nbPlayers > 2) {
        std::cerr << "Sorry bro, but your hacking skills are not efficient in this program." << std::endl;
        return (666);
    }

    if (ac == 5) {
        if (strcmp(av[4], "finite")) {
            std::cerr << "You must specify 'finite' for 4th parameter, nice try Mr Anderson." << std::endl;
            return (1337);
        }
        isFinite = true;
    }

    Kasparov game(w, h, isFinite);

    GeorgeRRMartin  got(game.getW(), game.getH());
    Rolex           rol;
    IGraphic *      g;

    srand(time(0));

    if (nbPlayers > 0) { game.addPlayer("wormtongue", eKeys::KEYLEFT1, eKeys::KEYRIGHT1, ePos::TOPLEFT, eColor::BLUE); }
    if (nbPlayers > 1) { game.addPlayer("gollum", eKeys::KEYLEFT2, eKeys::KEYRIGHT2, ePos::BOTRIGHT, eColor::RED); }

    got.setGraphic("sfml");
    g = got.getGraphic();

    g->start();

    eKeys key;
    int speed = 10;
    int now = rol.tick();

    Rolex speedRoll;
    int speedNow = speedRoll.tick();

    game.gyneco();
    std::list<Hiddleston *> players = game.getPlayers();

    while ((key = g->getInput()) != eKeys::ESCAPE && game.hasAlive()) {

        if (key == eKeys::ONE) { switchGraphic("sfml", &g, got); }
        if (key == eKeys::TWO) { switchGraphic("sdl", &g, got); }
        if (key == eKeys::THREE) { switchGraphic("ncurses", &g, got); }

        for (std::list<Hiddleston *>::iterator it = players.begin(); it != players.end(); ++it) {
            if ((*it)->isDead) { continue; }
            (*it)->digest(key);
        }

        if (rol.tick() - now > 1000 / speed) {
            g->clear();
            now = rol.tick();

            // let's draw the contours

            if (isFinite) {
                for (int i = 0; i < w; i++) { g->drawRect(i, 0, eColor::WHITE); }
                for (int i = 0; i < w; i++) { g->drawRect(i, h - 1, eColor::WHITE); }
                for (int i = 0; i < h; i++) { g->drawRect(0, i, eColor::WHITE); }
                for (int i = 0; i < h; i++) { g->drawRect(w - 1, i, eColor::WHITE); }
            }

            // let's draw players

            for (std::list<Hiddleston *>::iterator it = players.begin(); it != players.end(); ++it) {

                if ((*it)->isDead) { continue; }

                (*it)->apply();

                std::list< std::pair<int, int> > blocks = (*it)->getBlocks();
                std::list<std::pair<int, int> >::iterator i = blocks.begin();

                for (; i != blocks.end(); ++i) {
                    eColor color = (i == blocks.begin()) ? eColor::WHITE : (*it)->getColor();
                    g->drawRect((*i).first, (*i).second, color);
                }

            }

            // let's draw the big mac

            g->drawRect(game.getLunch().first, game.getLunch().second, eColor::YELLOW);

            // let's draw the score

            std::string msg;
            for (std::list<Hiddleston *>::iterator it = players.begin(); it != players.end(); ++it) {
                msg += (*it)->getName() + ": " + std::to_string((*it)->getBlocks().size() - 4) + "      ";
            }
            msg += "speed: " + std::to_string(speed);
            g->drawUi(msg);

            // finish drawing

            g->endDraw();
        }

        if (speedRoll.tick() - speedNow > 5e3) {
            speedNow = speedRoll.tick();
            speed += 5;
        }

    }

    g->end();

    std::cout << "--- The end ---" << std::endl;

    return (0);
}
