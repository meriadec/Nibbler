#ifndef NIBBLER_KASPAROV_H
#define NIBBLER_KASPAROV_H

# include <Hiddleston.hpp>
# include <vector>
# include <list>

class Kasparov {

public:

    std::vector< std::vector<int> > getMap (void) const;
    std::list<Hiddleston *> getPlayers (void) const;

    void addPlayer(std::string name, eKeys left, eKeys right);

    Kasparov (void);
    ~Kasparov (void);

private:

    std::vector< std::vector<int> > _map;
    std::list<Hiddleston *>         _players;

};

#endif
