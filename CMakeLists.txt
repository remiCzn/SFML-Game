cmake_minimum_required(VERSION 3.10)
project(SFML-Test VERSION 1.0)

set (CMAKE_CXX_STANDARD 14)

add_executable(SFML-Test
    src/main.cpp
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR ${CMAKE_SOURCE_DIR}/lib/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/lib/SFML/include)
include_directories(${CMAKE_SOURCE_DIR}/include)

target_link_libraries(SFML-Test sfml-system sfml-window sfml-graphics)