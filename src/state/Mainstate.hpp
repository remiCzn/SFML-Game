//
// Created by cazin on 11/11/2022.
//

#ifndef GAME_MAINSTATE_HPP
#define GAME_MAINSTATE_HPP


#include "../gameobject/Player.hpp"
#include "../tilemap/Tilemap.hpp"
#include "defines.h"
#include "../UI/Healthbar.hpp"

class Mainstate {
public:
    Mainstate();

    void render(const std::shared_ptr<sf::RenderTarget> &target);

    void update(const float &dt);

    void handleInput(const sf::Keyboard::Key &key);

private:
    Player player;
    Tilemap tilemap;
    std::shared_ptr<sf::View> view;

    Healthbar hearthBar;
};


#endif //GAME_MAINSTATE_HPP
