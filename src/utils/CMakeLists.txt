cmake_minimum_required (VERSION 3.28.3)

add_library(utils RandomNumberGenerator.cpp)

target_include_directories(utils
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})