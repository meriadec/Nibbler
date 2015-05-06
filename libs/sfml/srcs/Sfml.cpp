#include "Sfml.hpp"

Sfml::Sfml (int w, int h): _w(w), _h(h)
{
    _keyMap = {
            { sf::Keyboard::Left, eKeys::KEYLEFT },
            { sf::Keyboard::Right, eKeys::KEYRIGHT },
            { sf::Keyboard::Up, eKeys::KEYUP },
            { sf::Keyboard::Down, eKeys::KEYDOWN }
    };

    _colorMap = {
            { eColor::WHITE, sf::Color(253, 246, 227) },
            { eColor::BLACK, sf::Color(0, 43, 54) },
            { eColor::RED, sf::Color(220, 50, 47) },
            { eColor::BLUE, sf::Color(38, 139, 210) },
            { eColor::CYAN, sf::Color(42, 161, 152) },
            { eColor::GREEN, sf::Color(133, 153, 0) },
            { eColor::ORANGE, sf::Color(203, 75, 22) },
            { eColor::YELLOW , sf::Color(181, 137, 0) },
            { eColor::VIOLET, sf::Color(108, 113, 196) }
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
    _win->clear(_colorMap[eColor::BLACK]);
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

void Sfml::drawRect (int x, int y, eColor color)
{
    sf::RectangleShape rect(sf::Vector2f(10, 10));

    rect.setPosition(x, y);

    rect.setFillColor(_colorMap[color]);

    if (_win->isOpen()) {
        _win->draw(rect);
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
