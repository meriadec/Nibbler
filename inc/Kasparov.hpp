#ifndef NIBBLER_KASPAROV_H
#define NIBBLER_KASPAROV_H

# include <Hiddleston.hpp>
# include <nibbler.hpp>
# include <vector>
# include <list>

class Kasparov {

public:

    Kasparov (int w, int h);
    std::vector< std::vector<int> > getMap (void) const;
    std::list<Hiddleston *> getPlayers (void) const;

    void addPlayer(std::string name, eKeys left, eKeys right, ePos pos);

    int getW (void) const;
    int getH (void) const;

    Kasparov (void);
    ~Kasparov (void);

private:

    int _w;
    int _h;
    std::vector< std::vector<int> > _map;
    std::list<Hiddleston *>         _players;

};

#endif
