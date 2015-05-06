#include <Kasparov.hpp>

std::vector<std::vector<int> > Kasparov::getMap(void) const {
    return _map;
}

void Kasparov::addPlayer(std::string name, eKeys left, eKeys right) {
    _players.push_back(new Hiddleston(name, left, right));
}

Kasparov::~Kasparov (void) {
    for (std::list<Hiddleston *>::iterator it = _players.begin(); it != _players.end(); ++it) {
        delete *it;
    }
}

Kasparov::Kasparov (void) {

}

std::list<Hiddleston *> Kasparov::getPlayers (void) const {
    return _players;
}
