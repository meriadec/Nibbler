#ifndef NIBBLER_SDL_H
#define NIBBLER_SDL_H

# include <Sdl.h>

class Sdl {

    public:

        Sdl (int w, int h);
        ~Sdl (void);
        Sdl (Sdl const & ref);
        Sdl & operator= (Sdl const & ref);

        void start  (void);
        void end    (void);

    private:

        int             _w;
        int             _h;
        SDL_Window *    _win;
};

#endif
