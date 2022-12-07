#include "SocketClient.hpp"

SocketClient::SocketClient() {
    h.connect("http://localhost:3000");
}

void SocketClient::updatePosition(const sf::Vector2f position) {
    std::string message = "{\"x\":" + std::to_string(position.x) + ", \"y\":" + std::to_string(position.y) + "}";
    h.socket()->emit("position", message);
}
