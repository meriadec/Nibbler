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
  GeorgeRRMartin (void);
  ~GeorgeRRMartin (void);

  void setGraphic (std::string lib);


private:
  void *      _handle;
  IGraphic *  _g;

};

#endif
