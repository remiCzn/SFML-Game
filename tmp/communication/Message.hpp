#ifndef GAME_MESSAGE_HPP
#define GAME_MESSAGE_HPP

using MessageType = unsigned int;

struct Message {
    Message(const MessageType &l_type) : m_type(l_type) {}

    MessageType m_type;
    int m_sender;
    int m_receiver;

    union {
        bool m_bool;
        int m_int;
    };
};

#endif //GAME_MESSAGE_HPP
