#include"Events.h"

Sukien::Sukien(int a, std::string c){
    std::string b = std::to_string(a);
    std::string temp = 'c'+b+".png";
    cauhoi = IMG_Load(temp.c_str());
    temp = 'a'+b+".png";
    traloiA = IMG_Load(temp.c_str());
    temp = 'b'+b+".png";
    traloiB = IMG_Load(temp.c_str());
    nhanvat = IMG_Load(c.c_str());
};

Sukien::~Sukien(){
    SDL_FreeSurface(cauhoi);
    SDL_FreeSurface(traloiA);
    SDL_FreeSurface(traloiB);
    SDL_FreeSurface(nhanvat);
};

void show(Sukien a) {
    SDL_Rect temp {35,129,654,264};
    texture=SDL_CreateTextureFromSurface(renderer,a.cauhoi);
    SDL_RenderCopy(renderer,texture,NULL,&temp);
    SDL_RenderPresent(renderer);
    temp = {92,418,234,124};
    texture=SDL_CreateTextureFromSurface(renderer,a.traloiA);
    SDL_RenderCopy(renderer,texture,NULL,&temp);
    SDL_RenderPresent(renderer);
    temp = {398,418,234,124};
    texture=SDL_CreateTextureFromSurface(renderer,a.traloiB);
    SDL_RenderCopy(renderer,texture,NULL,&temp);
    SDL_RenderPresent(renderer);
    temp = {720,129,269,413};
    texture=SDL_CreateTextureFromSurface(renderer,a.nhanvat);
    SDL_RenderCopy(renderer,texture,NULL,&temp);
    SDL_RenderPresent(renderer);
};