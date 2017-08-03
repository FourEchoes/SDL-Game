//
//  Player.cpp
//  Test
//
//  Created by FourEchoes on 7/7/17.
//  Copyright © 2017 FourEchoes. All rights reserved.
//

#include "Player.hpp"
#include "Game.hpp"
#include <SDL_image.h>
#include <iostream>

using namespace std;

Player::Player(SDL_Renderer* r){
    SDL_Surface* surface;
    surface = IMG_Load("res/Player.png");
    texture = SDL_CreateTextureFromSurface(r, surface);
    SDL_FreeSurface(surface);
    renderer = r;
    
    SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);
    
    frameWidth = textureWidth / columns;
    frameHeight = textureHeight / rows;
    
    playerRect.x = playerRect.y = 0;
    playerRect.w = frameWidth;
    playerRect.h = frameHeight;
    
    playerPosition.x = playerPosition.y = 0;
    playerPosition.w = playerPosition.h = 50;
    
    ps = WALK_DOWN;
    
}

Player::~Player(){
    SDL_DestroyTexture(texture);
}

void Player::draw(){
    SDL_RenderCopy(renderer, texture, &playerRect, &playerPosition);
}

void Player::update(){
    frameTime++;
    if((FPS / frameTime) == 6){
        cout << "----" << endl;
        cout << "updating" << endl;
        if(ps == WALK_DOWN){
            cout << "set down " << frameHeight*10 << endl;
            animLim = 9;
            playerRect.y = (frameHeight*10); // 10 is the row for walking down animation
        }else if(ps == WALK_RIGHT){
            cout << "set right " << frameHeight*11 << endl;
            animLim = 9;
            playerRect.y = (frameHeight*11); // 11 is the row for walking right animation
        }else if(ps == WALK_LEFT){
            cout << "set left " << frameHeight*9 << endl;
            animLim = 9;
            playerRect.y = (frameHeight*9); // 9 is the row for walking left animation
        }else if(ps == WALK_UP){
            cout << "set up " << frameHeight*8 << endl;
            animLim = 9;
            playerRect.y = (frameHeight*8); // 8 is the row for walking up animation
        }
        cout << "playerRect.x (Before: " << playerRect.x;
        playerRect.x += frameWidth;
        cout << ", After: " << playerRect.x << ")" << endl;
        if(playerRect.x >= (frameWidth*animLim) || playerRect.x >= textureWidth){
            cout << "setting 0" << endl;
            playerRect.x = 0;
        }
        cout << "----" << endl;
        frameTime = 0;
    }
}

void Player::setPlayerState(const char* string){
    if(!strcmp(string, "WALK_RIGHT")){
        cout << "playerstate set right" << endl;
        ps = WALK_RIGHT;
    } else if(!strcmp(string, "WALK_LEFT")){
        cout << "playerstate set left" << endl;
        ps = WALK_LEFT;
    } else if(!strcmp(string, "WALK_DOWN")){
        cout << "playerstate set down" << endl;
        ps = WALK_DOWN;
    } else if(!strcmp(string, "WALK_UP")){
        cout << "playerstate set up" << endl;
        ps = WALK_UP;
    } else {
        cout << "Unknown PlayerState '" << string << "'" << endl;
    }
}

void Player::stop(){
    cout << "Okay... Stopping." << endl;
    playerRect.x = 0;
}

void Player::move(const char* string){
    int move = 2;
    if(!strcmp(string, "RIGHT")){
        playerPosition.x += move;
    }else if(!strcmp(string, "LEFT")){
        playerPosition.x -= move;
    }else if(!strcmp(string, "UP")){
        playerPosition.y -= move;
    }else if(!strcmp(string, "DOWN")){
        playerPosition.y += move;
    }
}

