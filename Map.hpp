//
//  Map.hpp
//  Test
//
//  Created by FourEchoes on 7/7/17.
//  Copyright © 2017 FourEchoes. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include <SDL.h>

class Map{
    int FPS = 60;
    int frameTime = 0;
    int frame = 0;
    SDL_Texture* texture[12];
    SDL_Renderer* renderer;
public:
    Map(SDL_Renderer*);
    ~Map();
    void draw();
};

#endif /* Map_hpp */
