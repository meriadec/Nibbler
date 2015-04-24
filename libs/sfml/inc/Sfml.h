#ifndef NIBBLER_SFML_H
#define NIBBLER_SFML_H

# include <SFML/Graphics.hpp>

class Sfml {

    public:

        Sfml (int w, int h);
        ~Sfml (void);
        Sfml (Sfml const & ref);
        Sfml & operator= (Sfml const & ref);

        const int & getWidth (void) const;
        const int & getHeight (void) const;

        void start  (void);
        void end    (void);

    private:

        int                 _w;
        int                 _h;
        sf::RenderWindow *  _win;

};

#endif
