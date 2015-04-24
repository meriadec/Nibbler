#include "nibbler.hpp"
#include "IGraphic.hpp"
#include <iostream>
#include <dlfcn.h>

int main (void)
{
    void * handle;
    IGraphic *(*graphic)(int, int);

    handle = dlopen("./libs/sfml/libsfml.so", RTLD_LOCAL);
    if (!handle) {
        std::cout << "Handle error." << std::endl;
        return (-1);
    }

    graphic = (IGraphic * (*)(int, int)) dlsym(handle, "create");
    if (!graphic) {
        std::cout << "Cannot link graphic." << std::endl;
    }

    IGraphic * g = graphic(1000, 1000);

    g->start();

    while (1) {

    }

    g->end();

    dlclose(handle);

    return (0);
}