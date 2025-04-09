# CMakeList.txt : CMake project for sfml-sorting, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.28.3)

add_subdirectory(shapes)
add_subdirectory(utils)
add_subdirectory(app)

add_executable (sfml-sorting main.cpp)

target_link_libraries(sfml-sorting application)

# TODO: Add tests and install targets if needed.
