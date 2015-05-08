cmake_minimum_required(VERSION 3.0.2)

set(EXECUTABLE_NAME sdl)
set(SDL_INCLUDE_DIR $ENV{HOME}/.brew/include)
set(SDL_LIBRARY $ENV{HOME}/.brew/lib/libSDL2.dylib)
set(SDL_TTF_LIBRARY $ENV{HOME}/.brew/Cellar/sdl2_ttf/2.0.12/lib/libSDL2_ttf.dylib)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -pedantic -std=c++11")
set(SOURCE_FILES srcs/Sdl.cpp)

find_package(SDL REQUIRED sdl2)

include_directories(inc)
include_directories(${SDL_INCLUDE_DIR})

add_library(${EXECUTABLE_NAME} MODULE ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE_NAME} ${SDL_LIBRARY} ${SDL_TTF_LIBRARY})
