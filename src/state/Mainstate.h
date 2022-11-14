//
// Created by cazin on 11/11/2022.
//

#ifndef GAME_MAINSTATE_H
#define GAME_MAINSTATE_H


#include "../gameobject/Player.h"
#include "../tilemap/Tilemap.h"
#include "defines.h"
#include "../UI/Healthbar.h"

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


#endif //GAME_MAINSTATE_H
