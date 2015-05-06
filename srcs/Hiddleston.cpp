#include <Hiddleston.hpp>
#include <Kasparov.hpp>

std::list<std::pair<int, int> > Hiddleston::getBlocks(void) const {
    return _blocks;
}

Hiddleston::Hiddleston(std::string name, eKeys left, eKeys right, ePos pos, Kasparov * game) : _name(name), _left(left), _right(right), _game(game) {
    _oneDirection = 0;
    if (pos == ePos::TOPLEFT) {
        _blocks.push_back(std::make_pair(1, 0));
        _blocks.push_back(std::make_pair(0, 0));
    } else if (pos == ePos::TOPRIGHT) {
        _blocks.push_back(std::make_pair(this->_game->getW() - 2, 0));
        _blocks.push_back(std::make_pair(this->_game->getW() - 1, 0));
    } else if (pos == ePos::BOTRIGHT) {
        _blocks.push_back(std::make_pair(this->_game->getW() - 2, this->_game->getH() - 1));
        _blocks.push_back(std::make_pair(this->_game->getW() - 1, this->_game->getH() - 1));
    } else if (pos == ePos::BOTLEFT) {
        _blocks.push_back(std::make_pair(1, this->_game->getH() - 1));
        _blocks.push_back(std::make_pair(0, this->_game->getH() - 1));
    }
}

void Hiddleston::digest(eKeys code) {
    if (code == _left) {
        _oneDirection--;
        if (_oneDirection < 0) {
            _oneDirection = 3;
        }
        std::cout << _name << " is moving left." << std::endl;
    }
    else if (code == _right) {
        _oneDirection++;
        if (_oneDirection > 3) {
            _oneDirection = 0;
        }
        std::cout << _name << " is moving right." << std::endl;
    }
}

std::string Hiddleston::getName (void) const {
    return _name;
}
