#ifndef GAME_ECS_TYPES_HPP
#define GAME_ECS_TYPES_HPP

enum class ComponentType {
    Position, SpriteSheet, State, Movable, Controller, Collidable
};

enum class SystemType {
    Renderer, Movement, Collision, Control, State, SheetAnimation
};
#endif //GAME_ECS_TYPES_HPP
