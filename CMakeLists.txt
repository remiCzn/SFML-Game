cmake_minimum_required(VERSION 3.12)

set(GAME_NAME Game)

project(${GAME_NAME} VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)


file(GLOB_RECURSE all_src
        CONFIGURE_DEPENDS
        "src/*.hpp"
        "src/*.cpp"
        )
add_executable(${GAME_NAME} ${all_src})


find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
find_package(jsoncpp REQUIRED)
find_package(TGUI REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(COPY assets/ DESTINATION ${CMAKE_BINARY_DIR}/assets)
target_link_libraries(${GAME_NAME} sfml-system sfml-window sfml-graphics jsoncpp_lib tgui)