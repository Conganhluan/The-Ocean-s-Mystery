#include"mainThings.h"
bool game::init(){
    if (SDL_Init(SDL_INIT_EVERYTHING)!=0) return false;
    window = SDL_CreateWindow(window,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1024,576,0);
    if (window==NULL) return false;
    renderer = SDL_CreateRenderer(window,-1,0);
    if (renderer==NULL) return false;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    return true;
}
