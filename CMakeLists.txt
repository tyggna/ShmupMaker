cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(ShmupMaker VERSION 0.1)
configure_file(ShmupMaker.h.in ShmupMaker.h)

# SDL2
set(SDL3_INCLUDE_DIR /usr/include/SDL3/)
set(SDL3_LIB_DIR /usr/lib/)
set(SDL3_IMAGE_INCLUDE_DIR /usr/include/SDL3_image/)
include_directories(${SDL3_INCLUDE_DIR} ${SDL3_IMAGE_INCLUDE_DIR})
link_directories(${SDL3_LIB_DIR})

file(
        DOWNLOAD
        https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.38.3/CPM.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
        EXPECTED_HASH SHA256=cc155ce02e7945e7b8967ddfaff0b050e958a723ef7aad3766d368940cb15494
)
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)

CPMAddPackage("gh:libsdl-org/SDL#4b429b9")
CPMAddPackage("gh:libsdl-org/SDL_image#6290d13")
CPMAddPackage("gh:libsdl-org/SDL_ttf#baf2e57")
CPMAddPackage("gh:libsdl-org/SDL_mixer#1bf7a79")
CPMAddPackage("gh:p-ranav/argparse@3.1")
CPMAddPackage("gh:nlohmann/json@3.11.3")

include_directories(.)

add_executable(ShmupMaker main.cpp
        configs.cpp
        configs.h
        defs.h
        sprites.cpp
        sprites.h
        scene.h
        scene.cpp
        SavegameHandler.cpp)
target_link_libraries(${PROJECT_NAME}
        SDL3::SDL3
        SDL3_image::SDL3_image
        SDL3_mixer::SDL3_mixer
        SDL3_ttf::SDL3_ttf
        nlohmann_json::nlohmann_json
        argparse::argparse)
target_include_directories(ShmupMaker PUBLIC
        "${PROJECT_BINARY_DIR}")
file(COPY confs DESTINATION ${CMAKE_CURRENT_BINARY_DIR})