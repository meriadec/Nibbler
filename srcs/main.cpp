#include <nibbler.hpp>
#include <IGraphic.hpp>
#include <Rolex.hpp>
#include <GeorgeRRMartin.hpp>
#include <Kasparov.hpp>

int main (int ac, char ** av)
{
    GeorgeRRMartin  got;
    Rolex           rol;
    IGraphic *      g;
    Kasparov        game(100, 100);

    game.addPlayer("pute", eKeys::KEYLEFT1, eKeys::KEYRIGHT1, ePos::TOPLEFT);
    game.addPlayer("boris", eKeys::KEYLEFT2, eKeys::KEYRIGHT2, ePos::BOTRIGHT);

    got.setGraphic(av[1]);
    g = got.getGraphic();

    g->start();

    eKeys key;
    int speed = 4;
    int now = rol.tick();
    std::list<Hiddleston *> players = game.getPlayers();

    while ((key = g->getInput()) != eKeys::ESCAPE) {

        for (std::list<Hiddleston *>::iterator it = players.begin(); it != players.end(); ++it) {
            (*it)->digest(key);
        }

        if (rol.tick() - now > 1000 / speed) {
            g->clear();
            now = rol.tick();


            for (std::list<Hiddleston *>::iterator it = players.begin(); it != players.end(); ++it) {

                std::list< std::pair<int, int> > blocks = (*it)->getBlocks();
                std::list<std::pair<int, int> >::iterator i = blocks.begin();

                for (; i != blocks.end(); ++i) {
                    g->drawRect((*i).first, (*i).second, eColor::BLUE);
                }

            }


            g->endDraw();
            std::cout << "updating draw and positions" << std::endl;
        }

    }

    g->end();

    return (0);
}
