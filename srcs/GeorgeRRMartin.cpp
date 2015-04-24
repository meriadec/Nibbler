#include <GeorgeRRMartin.hpp>

GeorgeRRMartin::GeorgeRRMartin (void) {
  _handle = NULL;
}

GeorgeRRMartin::~GeorgeRRMartin (void) {
}

void GeorgeRRMartin::setGraphic (std::string lib) {

  IGraphic *(*graphic)(int, int);

  if (_handle) {
    dlclose(_handle);
    _handle = NULL;
  }

  if (!(_handle = dlopen(("./libs/" + lib + "/lib" + lib + ".so").c_str(), RTLD_LOCAL))) {
    throw std::exception();
  }

  if (!(graphic = (IGraphic * (*)(int, int)) dlsym(_handle, "create"))) {
    throw std::exception();
  }

  _g = graphic(1000, 1000);
}
