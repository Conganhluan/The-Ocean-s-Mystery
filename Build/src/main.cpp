#include "Everythings.h"
#undef main
using namespace game;

int main() {
    
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("The Ocean's Mystery",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1024,576,0);
    renderer = SDL_CreateRenderer(window,-1, 0);
    texture = IMG_LoadTexture(renderer,"temp/pixel_people.png");
    SDL_RenderCopy(renderer,texture,NULL,NULL);
    SDL_RenderPresent(renderer);
    SDL_Delay(5000);
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;
}

