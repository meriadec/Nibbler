#include "Sdl.h"

Sdl::Sdl (int w, int h): _w(w), _h(h)
{
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
    return *this;
}

void Sdl::start (void)
{
    SDL_Init(SDL_INIT_VIDEO);
    _win = SDL_CreateWindow("Nibbler", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                            _w, _h, SDL_WINDOW_OPENGL);

    if (_win == NULL) {
        throw ();
    }
}

void Sdl::end (void)
{
    SDL_DestroyWindow(_w);
    SDL_Quit();
}