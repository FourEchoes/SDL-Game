//
//  Map.cpp
//  Test
//
//  Created by FourEchoes on 7/7/17.
//  Copyright © 2017 FourEchoes. All rights reserved.
//

#include "Map.hpp"
#include <SDL_image.h>
#include <iostream>

using namespace std;

Map::Map(SDL_Renderer* r){
    for(int i = 0; i < 12; i++){
        SDL_Surface* surface;
        char* string = "";
        if(i == 0){
            string = "res/map-1.png";
        } else if (i == 1){
            string = "res/map-2.png";
        } else if (i == 2){
            string = "res/map-3.png";
        } else if (i == 3){
            string = "res/map-4.png";
        } else if (i == 4){
            string = "res/map-5.png";
        } else if (i == 5){
            string = "res/map-6.png";
        } else if (i == 6){
            string = "res/map-7.png";
        } else if (i == 7){
            string = "res/map-8.png";
        } else if (i == 8){
            string = "res/map-9.png";
        } else if (i == 9){
            string = "res/map-10.png";
        } else if (i == 10){
            string = "res/map-11.png";
        } else if (i == 11){
            string = "res/map-12.png";
        }
        surface = IMG_Load(string);
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
