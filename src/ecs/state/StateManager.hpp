#ifndef GAME_STATEMANAGER_HPP
#define GAME_STATEMANAGER_HPP

#include <utility>
#include <vector>
#include <memory>
#include <unordered_map>
#include <functional>
#include "BaseState.hpp"
#include "../SharedContext.hpp"

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
    public:
        explicit StateManager(std::shared_ptr<SharedContext> shared) :
                shrdContext(std::move(shared)) {

        }

        ~StateManager() {
            for (auto &itr: this->states) {
                itr.second->onDestroy();
            }
        }

        void update(const float &dt) {
            if (this->states.empty()) {
                return;
            }
            if (this->states.back().second->isTranscendent()
                && this->states.size() > 1) {
                auto itr = this->states.end();
                while (itr != this->states.begin()) {
                    if (itr != this->states.end()) {
                        if (!itr->second->isTranscendent()) {
                            break;
                        }
                    }
                    --itr;
                }
                for (; itr != this->states.end(); ++itr) {
                    itr->second->update(dt);
                }
            } else {
                this->states.back().second->update(dt);
            }
        }

        void draw() {
            if (this->states.empty()) {
                return;
            }
            if (this->states.back().second->isTransparent()
                && this->states.size() > 1) {
                auto itr = this->states.end();
                while (itr != this->states.begin()) {
                    if (itr != this->states.end()) {
                        if (!itr->second->isTransparent()) {
                            break;
                        }
                    }
                    --itr;
                }
                for (; itr != this->states.end(); ++itr) {
                    itr->second->draw();
                }
            } else {
                this->states.back().second->draw();
            }
        }

        void processRequests() {
            while (this->toRemove.begin() != this->toRemove.end()) {
                this->removeState(*this->toRemove.begin());
                this->toRemove.erase(this->toRemove.begin());
            }
        }

        std::shared_ptr<SharedContext> getContext() {
            return this->shrdContext;
        }

        bool hasState(const StateType &type) {
            for (auto itr = this->states.begin(); itr != this->states.end(); ++itr) {
                if (itr->first == type) {
                    auto removed = std::find(this->toRemove.begin(), this->toRemove.end(), type);
                    if (removed == this->toRemove.end()) {
                        return true;
                    }
                    return false;
                }
            }
            return false;
        }

        void switchTo(const StateType &type) {
            this->shrdContext->eventManager->setCurrentState(type);
            for (auto itr = this->states.begin(); itr != this->states.end(); ++itr) {
                if (itr->first == type) {
                    this->states.back().second->deactivate();
                    StateType tmp = itr->first;
                    std::shared_ptr<BaseState> tmp_s = itr->second;
                    this->states.erase(itr);
                    this->states.emplace_back(tmp, tmp_s);
                    tmp_s->activate();
                    return;
                }
            }

            if (!this->states.empty()) {
                this->states.back().second->deactivate();
            }
            createState(type);
            this->states.back().second->activate();
        }

        void remove(const StateType &type) {
            this->toRemove.push_back(type);
        }

    private:
        void createState(const StateType &type) {
            auto newState = this->s_factory.find(type);
            if (newState == s_factory.end()) { return; }
            std::shared_ptr<BaseState> state = newState->second();
            this->states.emplace_back(type, state);
            state->onCreate();
        }

        void removeState(const StateType &type) {
            for (auto itr = this->states.begin(); itr != this->states.end(); ++itr) {
                if (itr->first == type) {
                    itr->second->onDestroy();
                    this->states.erase(itr);
                    return;
                }
            }
        }

        template<class T>
        void registerState(const StateType &type) {
            s_factory[type] = [this]() -> std::shared_ptr<BaseState> {
                return std::make_shared<T>(this);
            };
        }

        std::shared_ptr<SharedContext> shrdContext;
        StateContainer states;
        StateTypeContainer toRemove;
        StateFactory s_factory;
    };

}

#endif //GAME_STATEMANAGER_HPP
