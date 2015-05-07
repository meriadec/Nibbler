#ifndef NIBBLER_SDL_H
#define NIBBLER_SDL_H

# include <IGraphic.hpp>
# include <SDL2/SDL.h>
# include <map>
# include <vector>

class Sdl: public IGraphic {

    public:

        Sdl (int w, int h);
        ~Sdl (void);
        Sdl (Sdl const & ref);
        Sdl & operator= (Sdl const & ref);

        const int & getWidth (void) const;
        const int & getHeight (void) const;

        void start      (void);
        void end        (void);
        void clear      (void);
        void endDraw    (void);
        eKeys getInput  (void);

        void drawRect (int x, int y, eColor color);
        void drawUi (std::string msg);

    private:

        int             _w;
        int             _h;
        SDL_Window *    _win;
        SDL_Renderer *  _renderer;

        std::map<int, eKeys>                _keyMap;
        std::map<eColor, std::vector<int> > _colorMap;
};

#endif
