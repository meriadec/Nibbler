#include <Kasparov.hpp>

std::vector<std::vector<int> > Kasparov::getMap(void) const {
    return _map;
}

void Kasparov::addPlayer (std::string name, eKeys left, eKeys right, ePos pos, eColor color) {
    _players.push_back(new Hiddleston(name, left, right, pos, this, color));
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

Kasparov::Kasparov (int w, int h, bool isPinte) : _w(w), _h(h), isPinte(isPinte) {
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
    int maxH = this->isPinte ? this->_h - 1 : this->_h;
    int maxW = this->isPinte ? this->_w - 1 : this->_w;
    return std::make_pair(rand() % maxW, rand() % maxH);
}

std::pair<int, int> &Kasparov::getLunch (void) {
    return this->_bigMac;
}

bool Kasparov::hasAlive (void) {
    for (std::list<Hiddleston *>::iterator it = _players.begin(); it != _players.end(); it++) {
        if (!(*it)->isDead) { return true; }
    }
    return false;
}
