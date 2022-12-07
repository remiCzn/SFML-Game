#ifndef GAME_SOCKETCLIENT_HPP
#define GAME_SOCKETCLIENT_HPP

#include <sio_client.h>
#include <SFML/System/Vector2.hpp>

class SocketClient {
public:
    SocketClient();

    void updatePosition(const sf::Vector2f position);

private:

    sio::client h;
};


#endif //GAME_SOCKETCLIENT_HPP
