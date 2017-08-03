#include "Game.hpp"


int main(int argc, const char * argv[]) {
    Game *game = new Game();
    if(game->init("My Game", 800, 600, false)){
        while(game->gameRunning()){
            game->handleEvents();
            game->update();
            game->render();
            game->delay();
        }
    }
    return 0;
}
