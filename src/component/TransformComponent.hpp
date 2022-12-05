#ifndef GAME_TRANSFORMCOMPONENT_HPP
#define GAME_TRANSFORMCOMPONENT_HPP

#include "./Component.hpp"

class TransformComponent : public Component {
public:
    TransformComponent(Object *owner);

    void lateUpdate(const float &dt) override;

    void setPosition(float x, float y);

    void setPosition(const sf::Vector2f &pos);

    void translate(float x, float y);

    void translate(sf::Vector2f pos);

    void setX(float x);

    void setY(float y);

    void translateX(float x);

    void translateY(float y);

    const sf::Vector2f &getPosition() const;

    const sf::Vector2f &getPreviousFramePosition() const;

    void setStatic(bool isStatic);

    bool isStatic() const;

private:
    sf::Vector2f position;
    sf::Vector2f previousFramePosition;
    bool _isStatic;
};


#endif //GAME_TRANSFORMCOMPONENT_HPP
