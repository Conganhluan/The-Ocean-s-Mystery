#ifndef mainThings
#define  mainThings

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Surface* anhNen;
extern SDL_Texture* texture;
extern Mix_Music* nhacNen;
extern SDL_Event event;
extern TTF_Font* font;
extern SDL_Color mauchu;

extern short Money;
extern short Favor;
extern short Oxygen;
extern short Influ;
extern short Trans;
extern bool Death1;
extern bool Death2;
extern bool Death3;
extern bool Death4;
extern bool Death5;
extern bool Winning1;
extern bool Winning2;
extern bool Winning3;

namespace game {
    bool xoaNen(SDL_Surface* a);
    bool ganAnh(SDL_Surface* a, int x, int y);
    SDL_Surface* loadAnh(std::string a);
    void thaydoithuoctinh(char a, short b);
    void bienDoi();
}

#endif