#include "Button.hpp"

Button::Button() {
    this->_button = tgui::Button::create();
    this->_button->setTextSize(32);
    this->_button->getRenderer()->setTextColor(tgui::Color::White);
    this->_button->getRenderer()->setBackgroundColor(tgui::Color::Black);
}

void Button::setPosition(int x, int y) {
    this->_button->setPosition(x, y);
}

void Button::setText(const std::string &str) {
    this->_button->setText(str);
}

bool Button::isMouseDown() {
    bool value = this->_button->isMouseDown();
    this->_button->leftMouseButtonNoLongerDown();
    if (value) {
        this->_button->mouseNoLongerOnWidget();
    }
    return value;
}

tgui::Button::Ptr &Button::get() {
    return this->_button;
}
