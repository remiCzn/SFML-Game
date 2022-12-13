#include "EventManager.hpp"

void ECS::EventManager::setCurrentState(StateType state) {
    this->current_state = state;
}
