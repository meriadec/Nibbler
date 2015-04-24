#ifndef ROLEX_HPP
# define ROLEX_HPP

#include <nibbler.hpp>

#include <sys/time.h>

class Rolex {

public:
    Rolex(void);
    ~Rolex(void);

    int tick (void);

private:

    struct timeval      _start;

};

#endif
