#include <nibbler.hpp>
#include <IGraphic.hpp>
#include <Rolex.hpp>
#include <GeorgeRRMartin.hpp>
#include <Kasparov.hpp>

static void switchGraphic (std::string lib, IGraphic ** g, GeorgeRRMartin & got)
{
    if (got.setGraphic(lib)) {
        *g = got.getGraphic();
        (*g)->start();
    }
}

int main (int ac, char ** av)
{
    if (ac != 3) {
        std::cerr << "You should launch this program like: ./nibbler <width> <height>" << std::endl;
        return (42);
    }

    int w = std::atoi(av[1]);
    int h = std::atoi(av[2]);

    if (w < 50 || w > 100 || h < 50 || h > 100) {
        std::cerr << "Sorry bro, but your hacking skills are not efficient in this program." << std::endl;
        return (666);
    }

    Kasparov        game(w, h);

    GeorgeRRMartin  got(game.getW(), game.getH());
    Rolex           rol;
    IGraphic *      g;

    srand(time(0));

    game.addPlayer("joueur1", eKeys::KEYLEFT1, eKeys::KEYRIGHT1, ePos::TOPLEFT);
    game.addPlayer("joueur2", eKeys::KEYLEFT2, eKeys::KEYRIGHT2, ePos::BOTRIGHT);

    got.setGraphic("sfml");
    g = got.getGraphic();

    g->start();

    eKeys key;
    int speed = 50;
    int now = rol.tick();

    game.gyneco();
    std::list<Hiddleston *> players = game.getPlayers();

    while ((key = g->getInput()) != eKeys::ESCAPE && game.hasAlive()) {

        if (key == eKeys::ONE) { switchGraphic("sfml", &g, got); }
        if (key == eKeys::TWO) { switchGraphic("sdl", &g, got); }

        for (std::list<Hiddleston *>::iterator it = players.begin(); it != players.end(); ++it) {
            if ((*it)->isDead) { continue; }
            (*it)->digest(key);
        }

        if (rol.tick() - now > 1000 / speed) {
            g->clear();
            now = rol.tick();

            // let's draw players

            for (std::list<Hiddleston *>::iterator it = players.begin(); it != players.end(); ++it) {

                if ((*it)->isDead) { continue; }

                (*it)->apply();

                std::list< std::pair<int, int> > blocks = (*it)->getBlocks();
                std::list<std::pair<int, int> >::iterator i = blocks.begin();

                for (; i != blocks.end(); ++i) {
                    eColor color = (i == blocks.begin()) ? eColor::BLUE: eColor::CYAN;
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
            g->drawUi(msg);

            // finish drawing

            g->endDraw();
        }

    }

    g->end();

    std::cout << "--- The end ---" << std::endl;

    return (0);
}
