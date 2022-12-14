#ifndef GAME_EVENTMANAGER_HPP
#define GAME_EVENTMANAGER_HPP

#include <string>
#include <unordered_map>
#include <memory>
#include <functional>
#include <SFML/Window/Event.hpp>
#include <utility>
#include <SFML/Graphics/RenderWindow.hpp>

namespace ECS {
    enum class EventType {
        KeyDown = sf::Event::KeyPressed,
        KeyUp = sf::Event::KeyReleased,
        MButtonDown = sf::Event::MouseButtonPressed,
        MButtonUp = sf::Event::MouseButtonReleased,
        MouseWheel = sf::Event::MouseWheelMoved,
        WindowResized = sf::Event::Resized,
        GainedFocus = sf::Event::GainedFocus,
        LostFocus = sf::Event::LostFocus,
        MouseEntered = sf::Event::MouseEntered,
        MouseLeft = sf::Event::MouseLeft,
        Closed = sf::Event::Closed,
        TextEntered = sf::Event::TextEntered,
        Keyboard = sf::Event::Count + 1, Mouse, Joystick
    };

    struct EventInfo {
        EventInfo() { code = 0; }

        explicit EventInfo(int event) {
            code = event;
        }

        union {
            int code;
        };
    };

    struct EventDetails {
        explicit EventDetails(std::string bindname) : name(std::move(bindname)) {
            clear();
        }

        std::string name;
        sf::Vector2i size;
        sf::Uint32 textEntered{};
        sf::Vector2i mouse;
        int mouseWheelData{};
        int keycode{};

        void clear() {
            size = sf::Vector2i(0, 0);
            textEntered = 0;
            mouse = sf::Vector2i(0, 0);
            mouseWheelData = 0;
            keycode = -1;
        }
    };

    using Events = std::vector<std::pair<EventType, EventInfo>>;

    struct Binding {
        explicit Binding(const std::string &name) : name(name), details(name), c(0) {}

        ~Binding() = default;

        void bindEvent(EventType type, EventInfo info = EventInfo()) {
            events.emplace_back(type, info);
        }

        Events events;
        std::string name;
        int c;
        EventDetails details;
    };

    enum class StateType;
    using Bindings = std::unordered_map<std::string, std::shared_ptr<Binding>>;
    using CallbackContainer = std::unordered_map<std::string, std::function<void(std::shared_ptr<EventDetails>)>>;
    using Callbacks = std::unordered_map<StateType, CallbackContainer>;

    class EventManager {
    public:
        EventManager();

        ~EventManager();

        bool addBinding(std::shared_ptr<Binding> binding);

        bool removeBinding(std::string name);

        void setCurrentState(StateType state);

        void setFocus(const bool &focus);

        template<class T>
        bool addCallback(StateType state, const std::string &name, void(T::*func)(std::shared_ptr<EventDetails>),
                         T *instance) {
            auto itr = callbacks.emplace(state, CallbackContainer()).first;
            auto temp = std::bind(func, instance, std::placeholders::_1);
            return itr->second.emplace(name, temp).second;
        }

        bool removeCallback(StateType state, const std::string &name) {
            auto itr = callbacks.find(state);
            if (itr == callbacks.end()) { return false; }
            auto itr2 = itr->second.find(name);
            if (itr2 == itr->second.end()) { return false; }
            itr->second.erase(name);
            return true;
        }

        void handleEvent(sf::Event &event);

        void update();

        static sf::Vector2i getMousePos(const std::shared_ptr<sf::RenderWindow>& wind = nullptr) {
            return wind ? sf::Mouse::getPosition(*wind) : sf::Mouse::getPosition();
        }

    private:
        void loadBindings();

        StateType current_state;
        Bindings bindings;
        Callbacks callbacks;

        bool hasFocus;
    };
}

#endif //GAME_EVENTMANAGER_HPP
