set(LIBRARY_NAME application)

add_library(${LIBRARY_NAME} Application.cpp)

target_include_directories(${LIBRARY_NAME}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(application sfml-graphics sfml-audio shapes utils)
