#ifndef GAME_TRANSFORM_HPP
#define GAME_TRANSFORM_HPP

#include "./Component.hpp"

class Transform : public Component {
public:
    Transform(Object *owner);

    void setPosition(float x, float y);

    void setPosition(const sf::Vector2f &pos);

    void translate(float x, float y);

    void translate(sf::Vector2f pos);

    void setX(float x);

    void setY(float y);

    void translateX(float x);

    void translateY(float y);

    const sf::Vector2f &getPosition() const;

private:
    sf::Vector2f position;
};


#endif //GAME_TRANSFORM_HPP
