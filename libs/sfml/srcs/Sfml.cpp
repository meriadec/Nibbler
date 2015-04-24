#include "Sfml.hpp"

Sfml::Sfml (int w, int h): _w(w), _h(h)
{
    _keyMap = {
            { sf::Keyboard::Left, eKeys::KEYLEFT },
            { sf::Keyboard::Right, eKeys::KEYRIGHT },
            { sf::Keyboard::Up, eKeys::KEYUP },
            { sf::Keyboard::Down, eKeys::KEYDOWN }
    };
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

void Sfml::clear (void)
{
    _win->clear();
}

void Sfml::endDraw (void)
{
    _win->display();
}

eKeys Sfml::getInput (void)
{
    sf::Event event;
    while (_win->pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            return eKeys::ESCAPE;
        } else if (event.type == sf::Event::KeyPressed) {
            if (_keyMap.find(event.key.code) != _keyMap.end()) {
                return _keyMap[event.key.code];
            } else {
                return eKeys::NOTHING;
            }
        }
    }
    return eKeys::NOTHING;
}

extern "C" IGraphic * create (int w, int h)
{
    return new Sfml(w, h);
}

extern "C" void destroy (IGraphic * p)
{
    delete p;
}