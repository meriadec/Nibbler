#include "Sfml.hpp"

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

const int & Sfml::getHeight (void) const
{
    return _h;
}

const int & Sfml::getWidth (void) const
{
    return _w;
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

extern "C" IGraphic * create (int w, int h)
{
    return new Sfml(w, h);
}

extern "C" void destroy (IGraphic * p)
{
    delete p;
}