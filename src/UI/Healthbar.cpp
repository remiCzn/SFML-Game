#include "Healthbar.h"

Healthbar::Healthbar(int maxHealth) {
    this->currentHealth = maxHealth;
    this->maxHealth = maxHealth;
    if (!this->heartTexture.loadFromFile("assets/UI/hearts.png")) {
        std::cout << "Can't load heart texture" << std::endl;
    }
    this->fullHeart = sf::Sprite(this->heartTexture, sf::IntRect(0, 48, 16, 16));
    this->fullHeart.setScale(5, 5);
    this->halfHeart = sf::Sprite(this->heartTexture, sf::IntRect(32, 48, 16, 16));
    this->halfHeart.setScale(5, 5);
    this->emptyHeart = sf::Sprite(this->heartTexture, sf::IntRect(0, 0, 16, 16));
    this->emptyHeart.setScale(5, 5);

}

void Healthbar::addHealth(int nb) {
    this->currentHealth += nb;
    if (this->currentHealth > this->maxHealth) {
        this->currentHealth = this->maxHealth;
    } else if (this->currentHealth < 0) {
        this->currentHealth = 0;
    }
}

void Healthbar::render(const std::shared_ptr<sf::RenderTarget> &target) {
    int fullNb = this->currentHealth / 2;
    int halfNb = this->currentHealth % 2;
    int emptyNb = (this->maxHealth - this->currentHealth) / 2;

    for (int i = 0; i < fullNb; i++) {
        this->fullHeart.setPosition(i * 16 * 5 * 2 / 3, 0);
        target->draw(this->fullHeart);
    }
    for (int i = fullNb; i < fullNb + halfNb; i++) {
        this->halfHeart.setPosition(i * 16 * 5 * 2 / 3, 0);
        target->draw(this->halfHeart);
    }
    for (int i = fullNb + halfNb; i < fullNb + halfNb + emptyNb; i++) {
        this->emptyHeart.setPosition(i * 16 * 5 * 2 / 3, 0);
        target->draw(this->emptyHeart);
    }
}
