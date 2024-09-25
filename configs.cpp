//
// Created by tyggna on 9/23/24.
//
#include "configs.h"
using json = nlohmann::json;
using namespace std;

namespace confs {
    void gameconf::parse_conf() {
        int split = resolution.find('x');
        screen_width = stoi(resolution.substr(0,split));
        int rem = resolution.length() - split;
        screen_height = stoi(resolution.substr(split+1, rem));
        screen_size = {screen_width, screen_height};
        scalexy = {screen_size.first / simulation_size.first, screen_size.second / simulation_size.second};
    };
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(gameconf, resolution)
    gameconf load_gameconf() {
        string fname = CONFDIR;
        fname += "/config.json";
        std::ifstream f(fname);
        json conf_data = json::parse(f);
        confs::gameconf my_gameconf(conf_data);
        my_gameconf.parse_conf();
        return my_gameconf;
    };

    json load_conf(string filename, ConfType conftype = BASE)
    {
        string fname;
        switch(conftype) {
            case BASE:
                fname = CONFDIR;
                break;
            case ITEM:
                fname = ITEMCONFDIR;
                break;
            case LEVEL:
                fname = LEVELCONFDIR;
                break;
            case SEGMENT:
                fname = SEGMENTCONFDIR;
                break;
            case MOB:
                fname = MOBCONFDIR;
                break;
        }
        fname += filename;
        std::ifstream f(fname);
        json j = json::parse(f);
        return j;
    };

}

