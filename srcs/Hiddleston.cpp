#include <Hiddleston.hpp>

std::list<std::pair<int, int> > Hiddleston::getBlocks(void) const {
    return _blocks;
}

Hiddleston::Hiddleston(std::string name, eKeys left, eKeys right): _name(name), _left(left), _right(right) {
    _oneDirection = 0;
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
