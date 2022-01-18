#ifndef mainThings
#define  mainThings

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <string>
#include <cstdlib>



extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Surface* anhNen;
extern SDL_Texture* texture;
extern Mix_Music* nhacNen;
extern SDL_Event event;


extern short Money;
extern short Favor;
extern short Oxygen;
extern short Influ;
extern short Trans;
extern short ketThuc;
extern bool isRunning;
extern short khungNen;
extern short turn;



namespace game {
    void thaydoithuoctinh(char a, short b);
    void bienDoi();
    void showNen(int a);
}

#endif