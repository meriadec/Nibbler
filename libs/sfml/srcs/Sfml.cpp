#include "Sfml.h"

Sfml::Sfml (int w, int h): _w(w), _h(h)
{
}

Sfml::~Sfml (void)
{
}

Sfml::Sfml (Sfml const & ref)
{
    *this = ref;
}

Sfml & Sfml::operator= (Sfml const & ref)
{
    static_cast<void>(ref);
    return *this;
}

void Sfml::start (void)
{
    _win = new sf::RenderWindow(sf::VideoMode(_w, _h), "Nibbler");
}

void Sfml::end (void)
{
    if (_win->isOpen()) {
        _win->close();
    }
}