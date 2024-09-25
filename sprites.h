//
// Created by tyggna on 9/24/24.
//
#include <SDL3_image/SDL_image.h>
#include <map>
#include <string>

#ifndef SHMUPMAKER_SPRITES_H
#define SHMUPMAKER_SPRITES_H
class Animated {
public:
    Animated(std::string);
    std::string current_animation;
    int frame;
    std::map<std::string, std::pair<int, int>[]> animation_defs;
    SDL_Surface *asset;
};
#endif //SHMUPMAKER_SPRITES_H
