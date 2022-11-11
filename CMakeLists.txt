cmake_minimum_required(VERSION 3.12)

set(GAME_NAME Game)

project(${GAME_NAME} VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

file(GLOB_RECURSE all_src
        CONFIGURE_DEPENDS
        "src/*.h"
        "src/*.cpp"
        )

add_executable(${GAME_NAME} ${all_src} src/state/Mainstate.cpp src/state/Mainstate.h)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
find_package(jsoncpp CONFIG REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/lib/SFML/include)
include_directories(${CMAKE_SOURCE_DIR}/include)


file(COPY assets/ DESTINATION ${CMAKE_BINARY_DIR}/assets)

target_link_libraries(${GAME_NAME} sfml-system sfml-window sfml-graphics jsoncpp_lib)