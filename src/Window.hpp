#ifndef GAME_WINDOW_HPP
#define GAME_WINDOW_HPP

#include <string>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "ecs/EventManager.hpp"

class Window {
public:
    Window();

    Window(const std::string &title, const sf::Vector2u &size);

    ~Window();

    void beginDraw();

    void endDraw();

    void update();

    bool isDone() const;

    bool isFullscreen() const;

    bool isFocuses() const;

    void toggleFullscreen(const std::shared_ptr<ECS::EventDetails> &details);

    void close(const std::shared_ptr<ECS::EventDetails> & = nullptr);

    sf::RenderWindow *getRenderWindow();

    std::shared_ptr<ECS::EventManager> getEventManager();

    sf::Vector2u getWindowSize();

private:
    void setup(const std::string &title, const sf::Vector2u &size);

    void create();

    sf::RenderWindow window;
    ECS::EventManager eventManager;
    sf::Vector2u windowSize;
    std::string windowTitle;
    bool _isDone;
    bool _isFullscreen;
    bool _isFocused;
};


#endif //GAME_WINDOW_HPP
