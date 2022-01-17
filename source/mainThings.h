#ifndef mainThings
#define  mainThings

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Surface* anhNen = NULL;
SDL_Surface* tempAnhNen = NULL;
SDL_Texture* texture = NULL;
Mix_Music* nhacNen = NULL;

namespace game {
    bool init();
    void desteroy();
    bool xoaNen(SDL_Surface* a);
    bool ganAnh(SDL_Surface* a, int x, int y);
    SDL_Surface* loadAnh(std::string a);
    bool taoAnhNen();
}

#endif