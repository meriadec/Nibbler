#ifndef NIBBLER_NCURSES_H
#define NIBBLER_NCURSES_H

# include <IGraphic.hpp>
# include <ncurses.h>
# include <map>

class Ncurses : public IGraphic {

    public:

    Ncurses (int w, int h);
    ~Ncurses (void);

    void end (void);
    void clear (void);
    void endDraw (void);
    eKeys getInput (void);
    void drawRect (int x, int y, eColor color);
    void drawUi (std::string msg);

    const int & getWidth (void) const;
    const int & getHeight (void) const;

    void start (void);

    private:

    int _w;
    int _h;
    WINDOW *  _win;

    std::map<eColor, int> _colorMap;
    std::map<int, eKeys> _keyMap;

};

#endif
