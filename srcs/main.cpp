#include "nibbler.hpp"
#include "IGraphic.hpp"
#include <Rolex.hpp>
#include <GeorgeRRMartin.hpp>

int main (void)
{
    GeorgeRRMartin  got;
    Rolex           rol;
    IGraphic *      g;

    got.setGraphic("sfml");
    g = got.getGraphic();

    g->start();

    int speed = 4;
    int now = rol.tick();

    while (g->getInput() != eKeys::ESCAPE) {

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
