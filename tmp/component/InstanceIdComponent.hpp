#ifndef GAME_INSTANCEIDCOMPONENT_HPP
#define GAME_INSTANCEIDCOMPONENT_HPP

#include "Component.hpp"

class InstanceIdComponent : public Component {
public:
    InstanceIdComponent(Object *owner);

    ~InstanceIdComponent();

    int get() const;

private:
    static int count;
    int id;
};


#endif //GAME_INSTANCEIDCOMPONENT_HPP
