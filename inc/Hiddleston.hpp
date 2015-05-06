#ifndef NIBBLER_HIDDLESTON_H
#define NIBBLER_HIDDLESTON_H

# include <nibbler.hpp>
# include <utility>
# include <list>

class Kasparov;

class Hiddleston {

public:

    Hiddleston(std::string name, eKeys left, eKeys right, ePos pos, Kasparov * game);

    void digest (eKeys code);

    std::string getName (void) const;
    std::list<std::pair<int, int> > getBlocks (void) const;

private:

    std::list<std::pair<int, int> > _blocks;

    Kasparov * _game;
    std::string _name;
    eKeys _left;
    eKeys _right;
    int _oneDirection;

};

#endif