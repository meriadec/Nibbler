#include <Ncurses.hpp>
#include <nibbler.hpp>

Ncurses::Ncurses (int w, int h): _w(w), _h(h) {

}

Ncurses::~Ncurses (void) {

}

void Ncurses::start (void) {
    if (!initscr()) { throw std::exception(); }
    if (!has_colors()) {
        endwin();
        throw std::exception();
    }

    _win = newwin(_h, _w, 0, 0);
    getmaxyx(_win, _h, _w);

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_WHITE);
    init_pair(2, COLOR_WHITE, COLOR_GREEN);
    init_pair(3, COLOR_WHITE, COLOR_RED);
    init_pair(4, COLOR_WHITE, COLOR_BLUE);
    init_pair(5, COLOR_WHITE, COLOR_BLACK);
    init_pair(6, COLOR_WHITE, COLOR_YELLOW);
    init_pair(7, COLOR_WHITE, COLOR_MAGENTA);

    noecho();
    nodelay(stdscr, 1);
    keypad(stdscr, 1);
    wmove(this->_win, 0, 0);
    curs_set(0);

    _colorMap = {
        { eColor::WHITE, 1 },
        { eColor::BLACK, 2 },
        { eColor::RED, 3 },
        { eColor::BLUE, 4 },
        { eColor::CYAN, 5 },
        { eColor::GREEN, 1 },
        { eColor::ORANGE, 1 },
        { eColor::YELLOW, 6 },
        { eColor::VIOLET, 7 }
    };

    _keyMap = {
        { KEY_RIGHT, eKeys::KEYRIGHT1 },
        { KEY_LEFT, eKeys::KEYLEFT1 },
        { 100, eKeys::KEYRIGHT2 },
        { 97, eKeys::KEYLEFT2 },
        { 27, eKeys::ESCAPE },
        { 49, eKeys::ONE },
        { 50, eKeys::TWO }
    };
}

void Ncurses::end (void) {
    delwin(_win);
    endwin();
}

void Ncurses::clear (void) {
    werase(_win);
}

void Ncurses::endDraw (void) {
    wrefresh(_win);
}

eKeys Ncurses::getInput (void) {
    int ch;
    if ((ch = getch()) != ERR) {
        if (_keyMap.find(ch) != _keyMap.end()) {
            return _keyMap[ch];
        } else {
            return eKeys::NOTHING;
        }
    }
    return eKeys::NOTHING;
}

void Ncurses::drawRect (int x, int y, eColor color) {
    int c = COLOR_PAIR(_colorMap[color]);
    wattrset(_win, c);
    mvwaddch(_win, y, x * 2, ' ');
    mvwaddch(_win, y, x * 2 + 1, ' ');
    wattroff(_win, c);
}

void Ncurses::drawUi (std::string msg) {
    int c = COLOR_PAIR(_colorMap[eColor::VIOLET]);
    std::string pad;
    for (int i = 0; i < _w; i++) {
        pad += " ";
    }
    std::string full;
    for (int i = 0; i < _w; i++) {
        full += " ";
    }
    std::string out = " " + msg + pad;
    wattrset(_win, c);
    mvwaddstr(_win, _h - 3, 0, full.c_str());
    mvwaddstr(_win, _h - 2, 0, out.c_str());
    mvwaddstr(_win, _h - 1, 0, full.c_str());
    wattroff(_win, c);
}

const int & Ncurses::getWidth (void) const {
    return _w;
}

const int & Ncurses::getHeight (void) const {
    return _h;
}

extern "C" IGraphic * create (int w, int h) {
    return new Ncurses(w * 2, h);
}

extern "C" void destroy (IGraphic * p) {
    delete p;
}
