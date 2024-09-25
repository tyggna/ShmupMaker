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


set(JSON_INCLUDE_DIR /usr/include/nlohmann/)
include_directories(${JSON_INCLUDE_DIR})
find_package(nlohmann_json 3.11.3 REQUIRED)

include_directories(.)
include(FetchContent)
FetchContent_Declare(
        argparse
        GIT_REPOSITORY https://github.com/p-ranav/argparse.git
)

add_executable(ShmupMaker main.cpp
        configs.cpp
        configs.h
        defs.h
        sprites.cpp
        sprites.h)
target_link_libraries(${PROJECT_NAME} SDL3 SDL3_image nlohmann_json::nlohmann_json)
target_include_directories(ShmupMaker PUBLIC
        "${PROJECT_BINARY_DIR}")
file(COPY confs DESTINATION ${CMAKE_CURRENT_BINARY_DIR})