#ifndef NIBBLER_HIDDLESTON_H
#define NIBBLER_HIDDLESTON_H

# include <nibbler.hpp>
# include <utility>
# include <list>

class Kasparov;

class Hiddleston {

public:

    Hiddleston (std::string name, eKeys left, eKeys right, ePos pos, Kasparov *game, eColor color);

    void digest (eKeys code);
    void apply (void);

    std::string getName (void);
    std::list< std::pair<int, int> > getBlocks (void);

    bool isDead;

    eColor getColor (void) const;

private:

    std::list< std::pair<int, int> > _blocks;

    Kasparov * _game;
    std::string _name;
    void _uppercut (void);
    eKeys _left;
    eKeys _right;
    int _oneDirection;
    eColor _color;

};

#endif
