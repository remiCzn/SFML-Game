#ifndef GAME_OBSERVER_HPP
#define GAME_OBSERVER_HPP

#include "Message.hpp"

class Observer {
public:
    virtual void Notify(const Message &message) = 0;
};

#endif //GAME_OBSERVER_HPP
