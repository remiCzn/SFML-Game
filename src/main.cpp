#include <SFML/Graphics.hpp>
#include "defines.h"

int main() {

    sf::RenderWindow w(sf::VideoMode(800, 600), "Example Window");

    while (w.isOpen()) {

        sf::Event e;
        while (w.pollEvent(e)) {
            switch(e.type) {
                case sf::Event::Resized: w.setView(sf::View(sf::FloatRect(0, 0, e.size.width, e.size.height)));
                                         continue;
                case sf::Event::Closed:  w.close();
                                         continue;
            }
        }

        //Logical updates

        w.clear(sf::Color::Black);
        
        //Draw
        
        w.display();

    }
    //Ensure the window is closed
    w.close();
    return 0;
}