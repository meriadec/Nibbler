cmake_minimum_required(VERSION 3.0.2)

set(EXECUTABLE_NAME ncurses)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -pedantic -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES srcs/Ncurses.cpp)

include_directories(inc)

find_package(Curses REQUIRED)

add_library(${EXECUTABLE_NAME} MODULE ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE_NAME} ${CURSES_LIBRARY})
