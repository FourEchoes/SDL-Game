#include "Game.hpp"
#include <iostream>
#include "Map.hpp"
#include <SDL_image.h>

using namespace std;

Game::Game(){}

Game::~Game(){}

bool Game::init(const char *title, int xdim, int ydim, bool fullscreen){
    int flags = 0;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, xdim, ydim, flags);
    
    if(!window){
        cout << "Failed to create window! Error: " << SDL_GetError() << endl;
        return false;
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    if(!renderer){
        cout << "Failed to create renderer! Error: " << SDL_GetError() << endl;
        return false;
    }
    
    if(IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG){
        cout << "Failed to load map!" << endl;
        return false;
    }
    
    running = true;
    Player* player = new Player(renderer);
    players[0] = player;
    map = new Map(renderer);
    return true;
}

bool Game::gameRunning(){
    return running;
}

void Game::update(){
    frameTime++;
    if((FPS / frameTime) == 0){
        frameTime = 0;
    }
}

SDL_Renderer* Game::getRenderer(){
    return renderer;
}

void Game::render(){
    if(renderer != NULL){
        SDL_RenderClear(renderer);
        map->draw();
        players[0]->draw();
        SDL_RenderPresent(renderer);
    }
}

void Game::delay(){
    SDL_Delay(10);
}

void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_LEFT]) {
        cout << "LEFT is pressed!" << endl;
        players[0]->setPlayerState("WALK_LEFT");
        players[0]->update();
        players[0]->move("LEFT");
    } else if(state[SDL_SCANCODE_RIGHT]){
        cout << "RIGHT is pressed!" << endl;
        players[0]->setPlayerState("WALK_RIGHT");
        players[0]->update();
        players[0]->move("RIGHT");
    } else if(state[SDL_SCANCODE_UP]){
        cout << "UP is pressed!" << endl;
        players[0]->setPlayerState("WALK_UP");
        players[0]->update();
        players[0]->move("UP");
    } else if(state[SDL_SCANCODE_DOWN]){
        cout << "DOWN is pressed!" << endl;
        players[0]->setPlayerState("WALK_DOWN");
        players[0]->update();
        players[0]->move("DOWN");
    }
    if(event.type == SDL_KEYUP){
        switch(event.key.keysym.sym){
            case SDLK_w:
                cout << "W is released!" << endl;
                players[0]->stop();
                break;
            case SDLK_UP:
                cout << "UP is released!" << endl;
                players[0]->stop();
                break;
            case SDLK_a:
                cout << "A is released!" << endl;
                players[0]->stop();
                break;
            case SDLK_LEFT:
                cout << "LEFT is released!" << endl;
                players[0]->stop();
                break;
            case SDLK_s:
                cout << "S is released!" << endl;
                players[0]->stop();
                break;
            case SDLK_DOWN:
                cout << "DOWN is released!" << endl;
                players[0]->stop();
                break;
            case SDLK_d:
                cout << "D is released!" << endl;
                players[0]->stop();
                break;
            case SDLK_RIGHT:
                cout << "RIGHT is released!" << endl;
                players[0]->stop();
                break;
            default:
                break;
        }
    }
}

void Game::clean(){
    delete players[0];
    delete map;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    IMG_Quit();
    cout << "Game cleaned!" << endl;
}

