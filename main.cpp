#include <iostream>
#include <SDL3/SDL.h>
#include <nlohmann/json.hpp>
#include "ShmupMaker.h"
#include "configs.h"

using namespace std;

class GameRunner {
    public:
        const int play_area[2] = {480, 720};
        bool paused = false;
    GameRunner() {
// Load configs
        gameconf = confs::load_gameconf();
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            printf("Couldn't initialize SDL: %s\n", SDL_GetError());
            exit(1);
        }
        //auto t = std::tuple_cat(std::make_tuple("Shmup Maker"), std::make_tuple(window_flags));
        //window = std::apply(SDL_CreateWindow, t);
        window = SDL_CreateWindow("Shmup Maker",
                                  gameconf.screen_width,
                                  gameconf.screen_height,
                                  0
        );

    };
    private:
        bool _running = true;
        SDL_Surface* _display_surf = NULL;
        SDL_Window *window = NULL;
        SDL_Renderer *renderer = NULL;
        confs::gameconf gameconf;

};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        GameRunner game = GameRunner();
// report version
        std::cout << argv[0] << " Version " << ShmupMaker_VERSION_MAJOR << "."
                  << ShmupMaker_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }
}

