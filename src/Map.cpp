#include "Map.hpp"
#include <SDL_image.h>
#include <iostream>
#include <string>

using namespace std;

Map::Map(SDL_Renderer* r){
    for(int i = 0; i < 12; i++){
        SDL_Surface* surface;
        string path;
        path.append("resources/map/map-").append(to_string(i)).append(".png");
        cout << path.c_str() << endl;
        surface = IMG_Load(path.c_str());
        texture[i] = SDL_CreateTextureFromSurface(r, surface);
        SDL_FreeSurface(surface);
        renderer = r;
    }
}

Map::~Map(){
    for(int i = 0; i < 12; i++){
        if(texture[i] != NULL){
            SDL_DestroyTexture(texture[i]);
        }
    }
}

void Map::draw(){
    frameTime++;
    if((FPS / frameTime) == 4){
        if(frame >= 11){
            frame = 0;
        }
        frameTime = 0;
        frame++;
    }
    SDL_RenderCopy(renderer, texture[frame], NULL, NULL);
}
