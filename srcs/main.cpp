#include "nibbler.hpp"
#include "IGraphic.hpp"
#include <Rolex.hpp>
#include <GeorgeRRMartin.hpp>

int main (void)
{
    GeorgeRRMartin  got;
    Rolex           rol;
    IGraphic *      g;

    got.setGraphic("sdl");
    g = got.getGraphic();

    g->start();

    int speed = 4;
    int now = rol.tick();

    while (g->getInput() != eKeys::ESCAPE) {

        if (rol.tick() - now > 1000 / speed) {
            now = rol.tick();
            std::cout << "updating draw and positions" << std::endl;
        }

    }

    g->end();

    return (0);
}
