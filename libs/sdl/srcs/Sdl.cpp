#include "Sdl.hpp"

Sdl::Sdl (int w, int h): _w(w), _h(h)
{
    _keyMap = {
        { SDLK_LEFT, eKeys::KEYLEFT1 },
        { SDLK_RIGHT, eKeys::KEYRIGHT1 },
        { SDLK_a, eKeys::KEYLEFT2 },
        { SDLK_o, eKeys::KEYRIGHT2 }
    };

    _colorMap = {
            { eColor::WHITE, { 253, 246, 227 } },
            { eColor::BLACK, { 0, 43, 54 } },
            { eColor::RED, { 220, 50, 47 } },
            { eColor::BLUE, { 38, 139, 210 } },
            { eColor::CYAN, { 42, 161, 152 } },
            { eColor::GREEN, { 133, 153, 0 } },
            { eColor::ORANGE, { 203, 75, 22 } },
            { eColor::YELLOW , { 181, 137, 0 } },
            { eColor::VIOLET, { 108, 113, 196 } }
    };
}

Sdl::~Sdl (void)
{
}

Sdl::Sdl (Sdl const & ref)
{
    *this = ref;
}

Sdl & Sdl::operator= (Sdl const & ref)
{
    static_cast<void>(ref);
    return *this;
}

const int & Sdl::getHeight (void) const
{
    return _h;
}

const int & Sdl::getWidth (void) const
{
    return _w;
}

void Sdl::start (void)
{
    SDL_Init(SDL_INIT_VIDEO);
    _win = SDL_CreateWindow("Nibbler", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                            _w, _h, SDL_WINDOW_OPENGL);

    if (_win == NULL) {
        throw ("No window");
    }

    _renderer = SDL_CreateRenderer(_win, -1, 0);
}

void Sdl::end (void)
{
    SDL_DestroyWindow(_win);
    SDL_Quit();
}

void Sdl::clear (void)
{
    SDL_SetRenderDrawColor(_renderer, _colorMap[eColor::BLACK][0], _colorMap[eColor::BLACK][1], _colorMap[eColor::BLACK][2], 255);
    SDL_RenderClear(_renderer);
}

void Sdl::endDraw (void)
{
    SDL_RenderPresent(_renderer);
}

eKeys Sdl::getInput (void) {

    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return eKeys::ESCAPE;
        } else if (event.type == SDL_KEYDOWN) {
            if (_keyMap.find(event.key.keysym.sym) != _keyMap.end()) {
                return _keyMap[event.key.keysym.sym];
            } else {
                return eKeys::NOTHING;
            }
        }
    }
    return eKeys::NOTHING;
}

void Sdl::drawRect (int x, int y, eColor color)
{
    SDL_Rect rect = { x * 10, y * 10, 10, 10 };
    SDL_SetRenderDrawColor(_renderer, _colorMap[color][0], _colorMap[color][1], _colorMap[color][2], 255);
    SDL_RenderFillRect(_renderer, &rect);
};

extern "C" IGraphic * create (int w, int h)
{
    return new Sdl(w, h);
}

extern "C" void destroy (IGraphic * p)
{
    delete p;
}
