cmake_minimum_required(VERSION 3.12)

set(GAME_NAME Game)

project(${GAME_NAME} VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE all_src CONFIGURE_DEPENDS "src/*.h" "src/*.cpp")

add_executable(${GAME_NAME} ${all_src})

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR ${CMAKE_SOURCE_DIR}/lib/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/lib/SFML/include)
include_directories(${CMAKE_SOURCE_DIR}/include)

file(COPY assets/ DESTINATION ${CMAKE_BINARY_DIR}/assets)

target_link_libraries(${GAME_NAME} sfml-system sfml-window sfml-graphics)