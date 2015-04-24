#include "nibbler.hpp"
#include "IGraphic.hpp"
#include <Rolex.hpp>
#include <GeorgeRRMartin.hpp>

int main (void)
{
    GeorgeRRMartin  got;
    IGraphic * g;

    got.setGraphic("sdl");
    g = got.getGraphic();

    g->start();

    while (g->getInput() != eKeys::ESCAPE) {

    }

    g->end();

    return (0);
}
