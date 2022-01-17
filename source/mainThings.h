#ifndef mainThings
#define  mainThings

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Surface* mainSurface = NULL;
SDL_Texture* texture = NULL;
Mix_Music* music = NULL;

namespace game {
    int init();
}

#endif