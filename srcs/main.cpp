#include "nibbler.hpp"
#include "IGraphic.hpp"
#include <Rolex.hpp>
#include <GeorgeRRMartin.hpp>
#include <Kasparov.hpp>

int main (int ac, char ** av)
{
    GeorgeRRMartin  got;
    Rolex           rol;
    IGraphic *      g;
    Kasparov        game;

    game.addPlayer("pute", eKeys::KEYLEFT1, eKeys::KEYRIGHT1);
    game.addPlayer("boris", eKeys::KEYLEFT2, eKeys::KEYRIGHT2);

    got.setGraphic(av[1]);
    g = got.getGraphic();

    g->start();

    eKeys key;
    int speed = 4;
    int now = rol.tick();
    std::list<Hiddleston *> players = game.getPlayers();

    while ((key = g->getInput()) != eKeys::ESCAPE) {

        for (std::list<Hiddleston *>::const_iterator it = players.begin(); it != players.end(); ++it) {
            (*it)->digest(key);
        }

        if (rol.tick() - now > 1000 / speed) {
            g->clear();
            now = rol.tick();
            g->drawRect(0, 0, eColor::GREEN);

            g->endDraw();
            std::cout << "updating draw and positions" << std::endl;
        }

    }

    g->end();

    return (0);
}
