#include "Game.hpp"

int main() {
    Game game;

    while (game.isRunning()) {
        game.updateInput();
        game.update();
        game.lateUpdate();
        game.draw();
        game.updateDt();
    }
    return 0;
}