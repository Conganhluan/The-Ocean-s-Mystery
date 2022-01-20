#ifndef mainThings
#define mainThings

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>


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
extern bool stt[30];
extern bool collection[4];
extern bool Checkpoint;
extern short reNhanh;
extern short chuoi[20];

namespace game {
    void thaydoithuoctinh(char a, short b);
    void bienDoi();
    void showNen(int a);
    short layRandom();
    void napAttributes();
    void xoaAttributes();
    void showAttributes();
    void nhapfileCache();
    void xuatfileCache();
    void inKetthuc(short a);
    void inCollection();
    void inSukien(short a, short b);
    void inLoigioithieu();
    void setupAttribute();
}

#endif