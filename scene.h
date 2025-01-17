//
// Created by tyggna on 9/28/24.
//

#ifndef SHMUPMAKER_SCENE_H
#define SHMUPMAKER_SCENE_H
#include <map>
#include <string>
#include "configs.h"
using namespace std;
enum SceneType {
    SCENE_LEVEL,
    SCENE_MENU,
    SCENE_MAINMENU,
    SCENE_CUTSCENE
};
class Scene {
private:
    pair<int, int> screensize;
    pair<int, int> play_area;
    pair<float, float> scale;
public:
    Scene(const string filename);
    bool active;
    string name;
    SceneType stype;
    json level_j_def;
    void resize(pair<int,int> *newsize);
    virtual bool load() = 0;
    virtual void run() = 0;
    virtual void render() = 0;
};
class Level: public Scene {
private:
    vector<string> parts;
    vector<string> all_parts;
    vector<string> bg_filenames;
public:
    SceneType stype = SCENE_LEVEL;
    bool load();
    bool reset();
};

#endif //SHMUPMAKER_SCENE_H
