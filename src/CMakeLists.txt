# CMakeList.txt : CMake project for sfml-sorting, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

add_subdirectory(shapes)
add_subdirectory(utils)

add_executable (sfml-sorting sfml-sorting.cpp sfml-sorting.h)

target_link_libraries(sfml-sorting sfml-graphics sfml-audio shapes utils)

# TODO: Add tests and install targets if needed.
