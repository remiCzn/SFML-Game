#include "Game.hpp"

Game::Game() : stateManager(std::make_shared<ECS::SharedContext>(context)), dt(0) {

}

Game::~Game() = default;

void Game::update() {

}

void Game::render() {

}

void Game::lateUpdate() {

}

float Game::getDt() {

}

void Game::restartClock() {

}