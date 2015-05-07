#ifndef NIBBLER_SFML_H
#define NIBBLER_SFML_H

# include <IGraphic.hpp>
# include <SFML/Graphics.hpp>
# include <SFML/Window.hpp>
# include <map>

class Sfml: public IGraphic {

    public:

        Sfml (int w, int h);
        ~Sfml (void);
        Sfml (Sfml const & ref);
        Sfml & operator= (Sfml const & ref);

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

        int                 _w;
        int                 _h;
        sf::RenderWindow *  _win;

        std::map<int, eKeys>     _keyMap;
        std::map<eColor, sf::Color> _colorMap;

        sf::Font _font;

};

#endif
