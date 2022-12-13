#ifndef GAME_SHAREDCONTEXT_HPP
#define GAME_SHAREDCONTEXT_HPP

#include "EventManager.hpp"

namespace ECS {
    class SharedContext {
    public:
        SharedContext() : eventManager(nullptr) {};

        std::shared_ptr<EventManager> eventManager;
    };
}
#endif //GAME_SHAREDCONTEXT_HPP
