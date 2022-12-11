#ifndef GAME_GUY_HPP
#define GAME_GUY_HPP

#include "Object.hpp"
#include "../utils/ResourceManager.hpp"
#include "defines.hpp"
#include "../component/SpriteComponent.hpp"
#include "../component/AnimationComponent.hpp"
#include "constants.hpp"
#include "../component/collider/BoxColliderComponent.hpp"

class Guy : public Object {
public:
    explicit Guy(ResourceManager<sf::Texture> &textureAllocator);

    void update(const float &dt) override;

};


#endif //GAME_GUY_HPP
