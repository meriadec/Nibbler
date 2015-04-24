#include <Rolex.hpp>

Rolex::Rolex (void) {
  gettimeofday(&_start, NULL);
}

Rolex::~Rolex (void) {
  std::cout << "destructing rolex. Sorry Mr. Dray" << std::endl;
}

int Rolex::tick (void) {
  struct timeval stop;
  gettimeofday(&stop, NULL);
  return (stop.tv_usec - _start.tv_usec);
}
