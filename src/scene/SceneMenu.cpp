#include "SceneMenu.hpp"

SceneMenu::SceneMenu(SceneStateMachine &sceneStateMachine, Window &window) : Scene(window),
                                                                             stateMachine(sceneStateMachine),
                                                                             nextState(-1) {
    this->font.loadFromFile("assets/UI/dogicapixel.ttf");
    this->title.setPosition(sf::Vector2f(100, 100));
    this->title.setString("The Game");
    this->title.setFillColor(sf::Color::White);
    this->title.setFont(this->font);

    this->window.gui().setFont("assets/UI/dogicapixel.ttf");
    this->startButton = tgui::Button::create();
    this->startButton->setText("Start");
    this->startButton->setTextSize(32);
    this->startButton->setPosition(100, 175);
    this->startButton->getRenderer()->setTextColor(tgui::Color::White);
    this->startButton->getRenderer()->setBackgroundColor(tgui::Color::Black);

    this->quitMenu = tgui::Button::copy(this->startButton);
    this->quitMenu->setText("Quit");
    this->quitMenu->setPosition(100, 250);

}

void SceneMenu::update(const float &dt) {
    Scene::update(dt);
    if (this->startButton->isMouseDown()) {
        stateMachine.switchTo(this->nextState);
    } else if (this->quitMenu->isMouseDown()) {
        window.get().close();
    }
}

void SceneMenu::setNextState(unsigned int id) {
    this->nextState = id;
}

void SceneMenu::onCreate() {

}

void SceneMenu::onDestroy() {

}

void SceneMenu::draw() {
    window.gui().draw();
    window.draw(this->title);
}

void SceneMenu::onActivate() {
    window.gui().add(this->startButton);
    window.gui().add(this->quitMenu);
}

void SceneMenu::onDeactivate() {
    window.gui().remove(this->startButton);
    window.gui().remove(this->quitMenu);
}
