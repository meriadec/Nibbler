#ifndef GEORGERRMARTIN_HPP
# define GEORGERRMARTIN_HPP

#include <nibbler.hpp>
#include <IGraphic.hpp>

#include <dlfcn.h>

/*

             @@@@@
          ___(^_^)___
      >--(___________)--<
         (  _______  )
         _||       ||_
        (__)       (__)

 */

class GeorgeRRMartin {

public:

    GeorgeRRMartin(int w, int h);
    ~GeorgeRRMartin(void);

    bool setGraphic(std::string lib);
    IGraphic * getGraphic(void);

private:

    void * _handle;
    IGraphic * _g;
    std::string _current;

    int _w;
    int _h;

};

#endif
