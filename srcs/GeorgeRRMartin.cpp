#include <GeorgeRRMartin.hpp>

GeorgeRRMartin::GeorgeRRMartin (int w, int h): _w(w), _h(h) {
  _handle = NULL;
}

GeorgeRRMartin::~GeorgeRRMartin (void) {
}

bool GeorgeRRMartin::setGraphic(std::string lib) {

  if (_current == lib) { return false; }

  IGraphic *(*graphic)(int, int);

  if (_handle) {
    _g->end();
    dlclose(_handle);
    _handle = NULL;
  }

  if (!(_handle = dlopen(("./libs/" + lib + "/lib" + lib + ".so").c_str(), RTLD_LOCAL))) {
    throw std::exception();
  }

  if (!(graphic = (IGraphic * (*)(int, int)) dlsym(_handle, "create"))) {
    throw std::exception();
  }

  _g = graphic(_w, _h + 3);
  _current = lib;
  return true;
}

IGraphic *GeorgeRRMartin::getGraphic (void) {
  return _g;
}
