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
    getmaxyx(stdscr, _h, _w);

    _win = newwin(_h, _w, 0, 0);

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLUE);
    init_pair(5, COLOR_RED, COLOR_BLACK);

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
        { eColor::YELLOW, 1 },
        { eColor::VIOLET, 1 }
    };

    _keyMap = {
        { KEY_RIGHT, eKeys::KEYRIGHT1 },
        { KEY_LEFT, eKeys::KEYLEFT1 },
        { 111, eKeys::KEYRIGHT2 },
        { 97, eKeys::KEYLEFT2 },
        { 27, eKeys::ESCAPE },
        { 38, eKeys::ONE },
        { 91, eKeys::TWO }
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
    mvwaddch(_win, y, x, 'x' | _colorMap[color]);
}

void Ncurses::drawUi (std::string msg) {

}

const int & Ncurses::getWidth (void) const {
    return _w;
}

const int & Ncurses::getHeight (void) const {
    return _h;
}

extern "C" IGraphic * create (int w, int h) {
    return new Ncurses(w, h);
}

extern "C" void destroy (IGraphic * p) {
    delete p;
}
