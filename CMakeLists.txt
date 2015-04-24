cmake_minimum_required(VERSION 3.0.2)

project(Nibbler)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -pedantic -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -std=c++11")
set(EXECUTABLE_NAME nibbler)
set(SOURCE_FILES srcs/main.cpp)

include_directories(inc)

add_subdirectory(libs/sdl)
add_subdirectory(libs/sfml)

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE_NAME} ${CMAKE_DL_LIBS})