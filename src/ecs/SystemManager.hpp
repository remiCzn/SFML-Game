#ifndef GAME_SYSTEMMANAGER_HPP
#define GAME_SYSTEMMANAGER_HPP

#include "defines.hpp"
#include "EntityManager.hpp"
#include "ECS_Types.hpp"
#include "System.hpp"

class SystemManager {
public:
    SystemManager();

    ~SystemManager();

    void setEntityManager(std::shared_ptr<EntityManager> eMgr);


private:
    MapContainer<SystemType, System> systems;
};


#endif //GAME_SYSTEMMANAGER_HPP
