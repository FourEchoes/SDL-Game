//
//  Game.hpp
//  Test
//
//  Created by FourEchoes on 7/6/17.
//  Copyright © 2017 FourEchoes. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <SDL.h>
#include "Map.hpp"
#include "Player.hpp"

class Game{
    SDL_Window *window;
    SDL_Renderer *renderer;
    Map* map;
    bool running;
    Player* players[10];
    double r = 244;
    double g = 66;
    double b = 66;
    const int FPS = 60;
    int frameTime = 0;
public:
    Game();
    ~Game();
    
    bool init(const char* title, int xdim, int ydim, bool fullscreen);
    
    
    void handleEvents();
    void update();
    void render();
    
    bool gameRunning();
    
    void clean();
    int getFPS();
    void delay();
    int getFrameTime();
    
    SDL_Renderer* getRenderer();
    
};

#endif /* Game_hpp */
