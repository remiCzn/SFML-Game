#ifndef GAME_ENTITYMANAGER_HPP
#define GAME_ENTITYMANAGER_HPP


#include "SystemManager.hpp"

class SystemManager;

class EntityManager {
    EntityManager(std::shared_ptr<SystemManager> systemManager);

    ~EntityManager();

private:
};


#endif //GAME_ENTITYMANAGER_HPP
