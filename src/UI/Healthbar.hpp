#ifndef GAME_HEALTHBAR_HPP
#define GAME_HEALTHBAR_HPP

#include "defines.h"

class Healthbar {
public:
    Healthbar(int maxHealth);

    void addHealth(int nb);

    void render(const std::shared_ptr<sf::RenderTarget> &target);

private:
    sf::Sprite fullHeart;
    sf::Sprite emptyHeart;
    sf::Sprite halfHeart;
    sf::Texture heartTexture;

    int maxHealth;
    int currentHealth;
};


#endif //GAME_HEALTHBAR_HPP
