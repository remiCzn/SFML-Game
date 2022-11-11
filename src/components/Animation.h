#ifndef GAME_ANIMATION_H
#define GAME_ANIMATION_H

#include "defines.h"

template<typename T>
class Animation {
private:
    std::vector<T> frames;
    float delay;
    float time_counter;
    size_t current_frame;
public:
    Animation(std::vector<T> frames, float delay);

    bool tick(const float &dt); // return true if we go to the next frame
    const T &getFrame();
};


#endif //GAME_ANIMATION_H
