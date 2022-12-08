#ifndef GAME_BUTTON_HPP
#define GAME_BUTTON_HPP


#include <TGUI/Widgets/Button.hpp>

class Button {
public:
    Button();

    void setPosition(int x, int y);

    void setText(const std::string &str);

    bool isMouseDown();

    tgui::Button::Ptr &get();

private:
    tgui::Button::Ptr _button;
};


#endif //GAME_BUTTON_HPP
