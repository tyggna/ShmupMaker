//
// Created by tyggna on 9/24/24.
//
#include "sprites.h"

Animated::Animated(std::string filename ) {
    asset = IMG_Load(filename.c_str());
}