#ifndef NIBBLER_HIDDLESTON_H
#define NIBBLER_HIDDLESTON_H

#include <utility>
#include <list>
#include "IGraphic.hpp"

class Hiddleston {

public:

    Hiddleston (std::string name, eKeys left, eKeys right);

    void digest (eKeys code);

    std::string getName (void) const;
    std::list<std::pair<int, int> > getBlocks (void) const;

private:

    std::list<std::pair<int, int> > _blocks;

    std::string _name;
    eKeys _left;
    eKeys _right;
    int _oneDirection;

};

#endif
