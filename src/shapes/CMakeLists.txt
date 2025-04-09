cmake_minimum_required (VERSION 3.28.3)

add_library(shapes Bar.cpp)
target_include_directories(shapes
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})
