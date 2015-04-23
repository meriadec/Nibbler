cmake_minimum_required(VERSION 3.0.2)

set(EXECUTABLE_NAME sfml)
set(SFML_INCLUDE_DIR $ENV{HOME}/.brew/include)
set(SFML_ROOT $ENV{HOME}/.brew/lib)
set(CMAKE_MODULE_PATH $ENV{HOME}/.brew/Cellar/sfml/2.2/share/SFML/cmake/Modules)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -pedantic -std=c++11")
set(SOURCE_FILES srcs/Sfml.cpp)

find_package(SFML 2 REQUIRED system window graphics)

include_directories(inc)
include_directories(${SFML_INCLUDE_DIR})

add_library(${EXECUTABLE_NAME} MODULE ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})