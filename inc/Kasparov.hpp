#ifndef NIBBLER_KASPAROV_H
#define NIBBLER_KASPAROV_H

# include <Hiddleston.hpp>
# include <nibbler.hpp>
# include <vector>
# include <list>

class Kasparov {

public:

    Kasparov (int w, int h, bool isPinte);
    std::vector< std::vector<int> > getMap (void) const;
    std::list<Hiddleston *> getPlayers (void);

    void addPlayer (std::string name, eKeys left, eKeys right, ePos pos, eColor color);

    int getW (void) const;
    int getH (void) const;

    void gyneco (void);
    std::pair<int, int> & getLunch (void);

    Kasparov (void);
    ~Kasparov (void);

    bool hasAlive (void);
    bool isPinte;

private:

    int _w;
    int _h;
    std::vector< std::vector<int> > _map;
    std::list<Hiddleston *>         _players;
    std::list<Hiddleston *>         _playersToRemove;

    std::pair<int, int>             _bigMac;

    bool _isFree (std::pair<int, int> pos);
    std::pair<int, int>              _randomPos (void);

};

#endif
