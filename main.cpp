#include <iostream>
#include <SDL3/SDL.h>
#include <nlohmann/json.hpp>
#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>
#include "ShmupMaker.h"
#include "configs.h"
#include <argparse/argparse.hpp>

using namespace std;
SDL_Surface* _display_surf = NULL;
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
confs::gameconf gameconf;
bool paused = true;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {
    argparse::ArgumentParser program("ShmupMaker");
    program.add_argument("--version")
     .help("Print build version")
     .default_value(false)
     .implicit_value(true);
    try {
        program.parse_args(argc, argv);
    }
    catch (const std::exception& err) {
        cerr << err.what() << endl;
        cerr << program;
        return SDL_APP_FAILURE;
    }
    gameconf = confs::load_gameconf();
    if (program["--version"] == true) {
        std::cout << argv[0] << " Version " << ShmupMaker_VERSION_MAJOR << "."
                  << ShmupMaker_VERSION_MINOR << std::endl;
    }
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO)) {
        printf("SDL Failed to initialize");
        return SDL_APP_FAILURE;
    }
    window = SDL_CreateWindow("Shmup Maker",
                              gameconf.screen_width, gameconf.screen_height,
                              SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, "renderer");
    return SDL_APP_CONTINUE;
};

SDL_AppResult SDL_AppIterate(void *appstate) {
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    return SDL_APP_CONTINUE;
};

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *e) {
    if (e->type == SDL_EVENT_QUIT) {
        return SDL_APP_FAILURE;
    };
    return SDL_APP_CONTINUE;
};

void SDL_AppQuit(void *appstate) {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
};