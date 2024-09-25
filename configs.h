//
// Created by tyggna on 9/23/24.
//
#ifndef SHMUPMAKER_CONFIGS_H
#define SHMUPMAKER_CONFIGS_H
#define CONFDIR "confs/"
#define ITEMCONFDIR "confs/items/"
#define LEVELCONFDIR "confs/levels/"
#define SEGMENTCONFDIR "confs/levels/segments/"
#define MOBCONFDIR "confs/mobs/"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
using json = nlohmann::json;
enum ConfType {
   BASE,
   ITEM,
   LEVEL,
   SEGMENT,
   MOB
};
namespace confs{
    class gameconf {
        public:
            std::string resolution;
            int screen_width;
            int screen_height;
            std::pair<int, int> screen_size;
            std::pair<int, int> simulation_size = {480, 720};
            std::pair<float, float> scalexy;
            void parse_conf();
    };
    gameconf load_gameconf();
    json load_conf(std::string filename);

}
#endif //SHMUPMAKER_CONFIGS_H
