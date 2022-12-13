#ifndef GAME_STATEMANAGER_HPP
#define GAME_STATEMANAGER_HPP

#include <utility>
#include <vector>
#include <memory>
#include <unordered_map>
#include <functional>
#include "BaseState.hpp"

namespace ECS {
    enum class StateType {
        Intro = 1,
        MainMenu,
        Game,
        Paused,
        GameOver,
        Credits
    };
    using StateContainer = std::vector<std::pair<StateType, std::shared_ptr<BaseState>>>;
    using StateTypeContainer = std::vector<StateType>;
    using StateFactory = std::unordered_map<StateType, std::function<std::shared_ptr<BaseState>(void)>>;

    class StateManager {

    };

} // ECS

#endif //GAME_STATEMANAGER_HPP
