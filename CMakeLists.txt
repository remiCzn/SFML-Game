cmake_minimum_required(VERSION 3.10)

set(GAME_NAME Game)

project(${GAME_NAME} VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

add_executable(${GAME_NAME}
        src/main.cpp
        src/Game.cpp
        src/Game.h
        src/gameobject/Player.h
        src/components/GraphicsComponent.h
        src/gameobject/GameObject.cpp
        src/gameobject/GameObject.h
        src/components/GraphicsComponent.cpp
        src/components/InputComponent.h src/components/player/PlayerInputComponent.cpp src/components/player/PlayerInputComponent.h src/components/PhysicsComponent.h src/components/PhysicsComponent.cpp src/components/player/PlayerAnimationComponent.cpp src/components/player/PlayerAnimationComponent.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR ${CMAKE_SOURCE_DIR}/lib/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/lib/SFML/include)
include_directories(${CMAKE_SOURCE_DIR}/include)

configure_file(assets/character/chara1.png assets/character/chara1.png COPYONLY)

target_link_libraries(${GAME_NAME} sfml-system sfml-window sfml-graphics)