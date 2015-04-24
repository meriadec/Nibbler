#include "Sdl.hpp"

Sdl::Sdl (int w, int h): _w(w), _h(h)
{
    _keyMap = {
        { SDLK_LEFT, eKeys::KEYLEFT },
        { SDLK_RIGHT, eKeys::KEYRIGHT },
        { SDLK_UP, eKeys::KEYUP },
        { SDLK_DOWN, eKeys::KEYDOWN }
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

extern "C" IGraphic * create (int w, int h)
{
    return new Sdl(w, h);
}

extern "C" void destroy (IGraphic * p)
{
    delete p;
}