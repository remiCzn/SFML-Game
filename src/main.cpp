#include "Game.hpp"

int main() {
    Game game;

    while (game.isRunning()) {
        Input::update();
        game.update();
        game.lateUpdate();
        game.draw();
        game.updateDt();
    }
    return 0;
}