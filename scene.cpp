//
// Created by tyggna on 9/28/24.
//
#include "scene.h"

Scene::Scene(const std::string filename) {
    level_j_def = confs::load_conf(filename, LEVEL);
};

void Scene::resize(pair<int, int> *newsize) {
    scale = {(float)(newsize->first / play_area.first),
             (float)(newsize->second / play_area.second )};
    screensize = *newsize;
};

bool Level::load() {
    parts = (vector<string>)level_j_def.at("parts");
    all_parts = (vector<string>)level_j_def.at("parts");
    return true;
};

bool Level::reset() {
       parts = std::vector<string>(all_parts);
       return true;
};

