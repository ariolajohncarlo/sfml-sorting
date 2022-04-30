# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("sfml-sorting")

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

# Include sub-projects.
add_subdirectory ("sfml-sorting")
