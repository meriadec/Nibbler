#include <Rolex.hpp>

Rolex::Rolex (void) {
  gettimeofday(&_start, NULL);
}

Rolex::~Rolex (void) {
}

int Rolex::tick (void) {
  struct timeval stop;
  gettimeofday(&stop, NULL);
  return static_cast<int>(time(NULL) * 1000 + ((stop.tv_usec - _start.tv_usec) / 1000));
}
