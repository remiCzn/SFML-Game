#ifndef GAME_BASESTATE_HPP
#define GAME_BASESTATE_HPP

#include <memory>
#include <utility>

namespace ECS {
    class StateManager;

    class BaseState {
        friend class StateManager;

    public:
        explicit BaseState(std::shared_ptr<StateManager> stateManager) : stateManager(std::move(stateManager)),
                                                                         transcendent(false), transparent(false) {}

        virtual ~BaseState() = default;

        virtual void onCreate() = 0;

        virtual void activate() = 0;

        virtual void update(const float &dt) = 0;

        virtual void draw() = 0;

        virtual void deactivate() = 0;

        virtual void onDestroy() = 0;

        void setTransparent(const bool &t) { transparent = t; }

        bool isTransparent() const { return this->transparent; }

        void setTranscendent(const bool &t) { transcendent = t; }

        bool isTranscendent() const { return this->transcendent; }

    protected:
        std::shared_ptr<StateManager> stateManager;
        bool transparent;
        bool transcendent;

    };
}


#endif //GAME_BASESTATE_HPP
