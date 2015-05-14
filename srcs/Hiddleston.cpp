#include <Hiddleston.hpp>
#include <Kasparov.hpp>

std::list<std::pair<int, int> > Hiddleston::getBlocks (void) {
    return _blocks;
}

Hiddleston::Hiddleston (std::string name, eKeys left, eKeys right, ePos pos, Kasparov *game, eColor color) : _name(name), _left(left), _right(right), _game(game), isDead(false), _color(color) {
    _oneDirection = 1;

    if (pos == ePos::TOPLEFT) {
        _blocks.push_back(std::make_pair(4, 1));
        _blocks.push_back(std::make_pair(3, 1));
        _blocks.push_back(std::make_pair(2, 1));
        _blocks.push_back(std::make_pair(1, 1));
    } else if (pos == ePos::TOPRIGHT) {
        _blocks.push_back(std::make_pair(this->_game->getW() - 5, 1));
        _blocks.push_back(std::make_pair(this->_game->getW() - 4, 1));
        _blocks.push_back(std::make_pair(this->_game->getW() - 3, 1));
        _blocks.push_back(std::make_pair(this->_game->getW() - 2, 1));
        _oneDirection = 3;
    } else if (pos == ePos::BOTRIGHT) {
        _blocks.push_back(std::make_pair(this->_game->getW() - 5, this->_game->getH() - 2));
        _blocks.push_back(std::make_pair(this->_game->getW() - 4, this->_game->getH() - 2));
        _blocks.push_back(std::make_pair(this->_game->getW() - 3, this->_game->getH() - 2));
        _blocks.push_back(std::make_pair(this->_game->getW() - 2, this->_game->getH() - 2));
        _oneDirection = 3;
    } else if (pos == ePos::BOTLEFT) {
        _blocks.push_back(std::make_pair(4, this->_game->getH() - 2));
        _blocks.push_back(std::make_pair(3, this->_game->getH() - 2));
        _blocks.push_back(std::make_pair(2, this->_game->getH() - 2));
        _blocks.push_back(std::make_pair(1, this->_game->getH() - 2));
    }
}

void Hiddleston::digest (eKeys code) {
    if (code == _left) {
        _oneDirection--;
        if (_oneDirection < 0) { _oneDirection = 3; }
    }
    else if (code == _right) {
        _oneDirection++;
        if (_oneDirection > 3) { _oneDirection = 0; }
    }
}

std::string Hiddleston::getName (void) {
    return _name;
}

void Hiddleston::apply (void) {
    std::pair<int, int> el = _blocks.front();

         if (_oneDirection == 0) { _blocks.push_front(std::make_pair(el.first, el.second - 1)); }
    else if (_oneDirection == 1) { _blocks.push_front(std::make_pair(el.first + 1, el.second)); }
    else if (_oneDirection == 2) { _blocks.push_front(std::make_pair(el.first, el.second + 1)); }
    else if (_oneDirection == 3) { _blocks.push_front(std::make_pair(el.first - 1, el.second)); }

    _uppercut();

    el = _blocks.front();

    // check if dead

    if (this->_game->isPinte) {
        if (el.first == 0 || el.first == this->_game->getW() - 1 || el.second == 0 || el.second == this->_game->getH() - 1) {
            this->isDead = true;
            return;
        }
    }

    std::list<Hiddleston *> players = this->_game->getPlayers();
    for (std::list<Hiddleston *>::iterator it = players.begin(); it != players.end(); ++it) {
        if ((*it)->isDead) { continue; }
        std::list< std::pair<int, int> > blocks = (*it)->getBlocks();
        std::list< std::pair<int, int> >::iterator i = ((*it) == this) ? std::next(blocks.begin(), 1) : blocks.begin();
        for (; i != blocks.end(); ++i) {
            if ((*i) == el) {
                this->isDead = true;
                return;
            }
        }
    }

    // check if eat

    if (el == this->_game->getLunch()) {
        this->_game->gyneco();
    } else {
        _blocks.pop_back();
    }

}

void Hiddleston::_uppercut (void) {

    int h = this->_game->getH() - 1;
    int w = this->_game->getW() - 1;

    std::pair<int, int> & el = _blocks.front();

         if (el.first < 0)  { el.first = w;}
    else if (el.first > w)  { el.first = 0; }
    else if (el.second < 0) { el.second = h; }
    else if (el.second > h) { el.second = 0; }

}

eColor Hiddleston::getColor (void) const {
    return _color;
}
