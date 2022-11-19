cmake_minimum_required(VERSION 3.12)

set(GAME_NAME Game)

project(${GAME_NAME} VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)


file(GLOB_RECURSE all_src
        CONFIGURE_DEPENDS
        "src/*.hpp"
        "src/*.cpp"
        )
add_executable(${GAME_NAME} ${all_src})


find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
find_package(jsoncpp REQUIRED)
find_package(GTest CONFIG REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${VCPKG_PATH}/installed/x64-windows/include)

file(COPY assets/ DESTINATION ${CMAKE_BINARY_DIR}/assets)
target_link_libraries(${GAME_NAME} sfml-system sfml-window sfml-graphics jsoncpp_lib GTest::gtest)