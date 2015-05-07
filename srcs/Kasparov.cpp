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

void Kasparov::gyneco (void) {
    int xavier = false;
    std::pair<int, int> pos;
    while (!xavier) {
        pos = _randomPos();
        xavier = _isFree(pos);
    }
    _bigMac = pos;
}

bool Kasparov::_isFree (std::pair<int, int> pos) {
    if (pos == _bigMac) { return false; }
    for (std::list<Hiddleston *>::iterator it = _players.begin(); it != _players.end(); it++) {
        std::list< std::pair<int, int> > blocks = (*it)->getBlocks();
        for (std::list< std::pair<int, int> >::iterator it2 = blocks.begin(); it2 != blocks.end(); it2++) {
            if (pos == (*it2)) { return false; }
        }
    }
    return true;
}

std::pair<int, int> Kasparov::_randomPos (void) {
    return std::make_pair(rand() % this->_w, rand() % this->_h);
}

std::pair<int, int> &Kasparov::getLunch (void) {
    return this->_bigMac;
}
