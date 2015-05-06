#include <Kasparov.hpp>

std::vector<std::vector<int> > Kasparov::getMap(void) const {
    return _map;
}

void Kasparov::addPlayer(std::string name, eKeys left, eKeys right, ePos pos) {
    _players.push_back(new Hiddleston(name, left, right, pos, this));
}

Kasparov::~Kasparov (void) {
    for (std::list<Hiddleston *>::iterator it = _players.begin(); it != _players.end(); ++it) {
        delete *it;
    }
}

Kasparov::Kasparov (void) {

}

std::list<Hiddleston *> Kasparov::getPlayers (void) {
    return _players;
}

Kasparov::Kasparov(int w, int h): _w(w), _h(h) {
}

int Kasparov::getH (void) const {
    return _h;
}

int Kasparov::getW (void) const {
    return _w;
}
