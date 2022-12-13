#ifndef GAME_EVENTMANAGER_HPP
#define GAME_EVENTMANAGER_HPP

#include <string>
#include <unordered_map>
#include <memory>
#include <functional>

struct EventDetails {
    //TODO
};

struct Binding {
    //TODO
};

namespace ECS {
    enum class StateType;
    using Bindings = std::unordered_map<std::string, std::shared_ptr<Binding>>;
    using CallbackContainer = std::unordered_map<std::string, std::function<void(std::shared_ptr<EventDetails>)>>;
    using Callbacks = std::unordered_map<StateType, CallbackContainer>;

    class EventManager {
    public:
        void setCurrentState(StateType state);

    private:
        StateType current_state;
        Bindings bindings;
        Callbacks callbacks;

        bool hasFocus;
    };
}

#endif //GAME_EVENTMANAGER_HPP
