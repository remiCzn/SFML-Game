#ifndef GAME_COMMUNICATOR_HPP
#define GAME_COMMUNICATOR_HPP

#include "defines.hpp"
#include "Observer.hpp"

class Communicator {
public:
    bool addObserver(const std::shared_ptr<Observer> &observer) {
        if (hasObserver(observer)) {
            return false;
        }
        observers.emplace_back(observer);
        return true;
    };

    bool removeObserver(const std::shared_ptr<Observer> &observer) {
        for (auto it = observers.begin(); it < observers.end(); it++) {
            if (*it == observer) {
                observers.erase(it);
                return true;
            }
        }
        return false;
    };

    bool hasObserver(const std::shared_ptr<Observer> observer) {
        return (std::find_if(observers.begin(), observers.end(),
                             [&observer](std::shared_ptr<Observer> o) { return o == observer; }) != observers.end());
    };

private:
    Container<Observer> observers;
};

#endif //GAME_COMMUNICATOR_HPP
