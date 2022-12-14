#include "EventManager.hpp"

namespace ECS {
    void EventManager::setCurrentState(StateType state) {
        this->current_state = state;
    }

    EventManager::EventManager(): current_state(StateType(0)), hasFocus(true) {
        loadBindings();
    }

    EventManager::~EventManager() = default;

    bool EventManager::addBinding(std::shared_ptr<Binding> binding) {
        if(this->bindings.find(binding->name) != bindings.end()) {
            return false;
        }
        return bindings.emplace(binding->name, binding).second;
    }

    bool EventManager::removeBinding(std::string name) {
        auto itr = bindings.find(name);
        if(itr == bindings.end()) {return false;}
        bindings.erase(itr);
        return true;
    }

    void EventManager::setFocus(const bool &focus) {
        hasFocus = focus;
    }

    void EventManager::handleEvent(sf::Event &event) {

    }

    void EventManager::update() {

    }

    void EventManager::loadBindings() {

    }
}

