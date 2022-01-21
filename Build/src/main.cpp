#include "Everythings.h"
#undef main
using namespace game;

int main() {
    
    //Init everything
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("The Ocean's Mystery",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,0);
    renderer = SDL_CreateRenderer(window,-1,0);
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 0);
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
    music = Mix_LoadMUS("resouce/sounds/bgmusic.mp3");
    Mix_VolumeMusic(20);
    Mix_PlayMusic(music,-1);
    inCache();
    gameEvent game_event;


    //Main loop
    while (isRunning) {
        switch (bgNumber) {
            case 0:
                gameCase::welcomeCase();
                break;
            case 1: 
                gameCase::welcomeCase();
                break;
            case 2:
                gameCase::mainCase();
                break;
            case 3:
                gameCase::mainCase();
                break;
            case 4:
                gameCase::creditCase();
                break;
            case 5:
                gameCase::collectionCase();
                break;
            case 6:
                gameCase::storyCase();
                break;
        }
    }



    //Destroy everything
    outCache();
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    Mix_PauseMusic();
    Mix_CloseAudio();
    SDL_Quit();
    return 0;
}

