#ifndef NIBBLER_SDL_H
#define NIBBLER_SDL_H

# include <IGraphic.hpp>
# include <SDL2/SDL.h>

class Sdl: public IGraphic {

    public:

        Sdl (int w, int h);
        ~Sdl (void);
        Sdl (Sdl const & ref);
        Sdl & operator= (Sdl const & ref);

        const int & getWidth (void) const;
        const int & getHeight (void) const;

        void start  (void);
        void end    (void);

    private:

        int             _w;
        int             _h;
        SDL_Window *    _win;
};

#endif
