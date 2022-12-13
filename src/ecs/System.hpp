#ifndef GAME_SYSTEM_HPP
#define GAME_SYSTEM_HPP

#include "../communication/Observer.hpp"
#include "../objects/Object.hpp"
#include "ECS_Types.hpp"
#include "SystemManager.hpp"

class SystemManager;

class System : public Observer {
public:
    System();

    virtual ~System();

    bool add(const std::shared_ptr<Object> &object);

    bool has(const std::shared_ptr<Object> &object);

    bool remove(const std::shared_ptr<Object> &object);

    SystemType getId();

    void purge();

    virtual void update(const float &dt) = 0;

    virtual void handleEvent(const std::shared_ptr<Object> &object) = 0;

protected:
    SystemType id;
    Container<Object> objectList;
    std::shared_ptr<SystemManager> systemManager;
};


#endif //GAME_SYSTEM_HPP
