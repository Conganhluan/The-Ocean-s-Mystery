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
    posCauhoi = {35,129,654,264};
    postraloiA = {92,418,234,124};
    postraloiB = {398,418,234,124};
    posNhanvat = {720,129,269,413};
    sttSukien = a;
};

Sukien::~Sukien(){
    SDL_FreeSurface(cauhoi);
    SDL_FreeSurface(traloiA);
    SDL_FreeSurface(traloiB);
    SDL_FreeSurface(nhanvat);
    posCauhoi = {0,0,0,0};
    postraloiA = {0,0,0,0};
    postraloiB = {0,0,0,0};
    posNhanvat = {0,0,0,0};
    sttSuKien = 0;
};

void show(Sukien a) {
    texture=SDL_CreateTextureFromSurface(renderer,a.cauhoi);
    SDL_RenderCopy(renderer,texture,NULL,a.posCauhoi);
    texture=SDL_CreateTextureFromSurface(renderer,a.posTraloiA);
    SDL_RenderCopy(renderer,texture,NULL,a.posTraloiA);
    texture=SDL_CreateTextureFromSurface(renderer,a.posTraloiB);
    SDL_RenderCopy(renderer,texture,NULL,a.posTraloiB);
    texture=SDL_CreateTextureFromSurface(renderer,a.nhanvat);
    SDL_RenderCopy(renderer,texture,NULL,a.posNhanvat);
    SDL_RenderPresent(renderer);
};

void explain(Sukien a, bool b) {
    SDL_RenderClear(renderer);
    game::showNen(khungNen);
    std::string c = 'd'+std::to_string(a.sttSukien);
    (b)?c+='b':c+='a';
    c+=".png";
    texture=IMG_LoadTexture(renderer,c.c_str());
    SDL_RenderCopy(renderer,texture,NULL,a.posCauhoi);
    SDL_RenderPresent(renderer);
}