#include"mainThings.h"

bool game::xoaNen(SDL_Surface* a){
    if (SDL_SetColorKey(a,SDL_TRUE,SDL_MapRGB(a->format,255,192,203))!=0) return false;
    return true;
};

bool game::ganAnh(SDL_Surface* a, int x, int y) {
    SDL_Rect rect;
    rect.x=x;
    rect.y=y;
    if (SDL_BlitSurface(a,NULL,anhNen,&rect)!=0) return false;
    return true;
};

SDL_Surface* game::loadAnh(std::string a) {
    SDL_Surface* result = NULL;
    result = IMG_Load(a.c_str());
    return result;
};

void game::thaydoithuoctinh(char a, short b) {
    switch (a) {
        case 'M': 
            Money+=b;
            if (Money>=100) Winning1=true;
            else if (Money<=0) Death1=true;
            break;
        case 'F':
            Favor+=b;
            if (Favor<=0) Death2=true;
            else if (Favor>=100) Winning3=true;
            break;
        case 'O':
            Oxygen+=b;
            if (Oxygen<=0) Death3=true;
            else if (Oxygen>100) Oxygen=100;
            break;
        case 'I':
            Influ+=b;
            if (Influ>=100) Winning2=true;
            else if (Influ<=0) Death4=true;
            break;
        case 'T':
            Trans+=b;
            if (Trans>=100) Death5=true;
            else if (Trans<0) Trans=0;
    }
}

void game::bienDoi(){
    thaydoithuoctinh('O',-10);
    thaydoithuoctinh('T',5);
}