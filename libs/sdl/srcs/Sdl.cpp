#include "Sdl.hpp"

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

extern "C" IGraphic * create (int w, int h)
{
    return new Sdl(w, h);
}

extern "C" void destroy (IGraphic * p)
{
    delete p;
}