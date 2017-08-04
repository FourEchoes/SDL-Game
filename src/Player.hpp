#ifndef Player_hpp
#define Player_hpp

#include <SDL.h>
#include <stdio.h>

class Player{
    int x;
    int y;
    const int FPS = 60;
    int frameTime = 0;
    
    SDL_Texture* texture;
    SDL_Renderer* renderer;
    
    SDL_Rect playerRect;
    SDL_Rect playerPosition;
    
    int textureHeight, textureWidth;
    int frameHeight, frameWidth;
    int animLim; // Limit of columns (So it doesn't show invisible when it has less columns than 'columns')
    
    int columns = 13; // width
    int rows = 21; // height
public:
    enum PlayerState { WALK_LEFT, WALK_RIGHT, WALK_UP, WALK_DOWN };
    PlayerState ps;
    Player(SDL_Renderer*);
    ~Player();
    
    void update();
    void draw();
    void stop();
    void setPlayerState(const char*);
    void move(const char*);
    
};

#endif
