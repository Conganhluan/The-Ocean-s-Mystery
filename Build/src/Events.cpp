#include"Events.h"

Sukien::Sukien(int a){
    std::string b = std::to_string(a);
    std::string temp = 'c'+b+".png";
    cauhoi = IMG_Load(temp.c_str());
    temp = 'a'+b+".png";
    traloiA = IMG_Load(temp.c_str());
    temp = 'b'+b+".png";
    traloiB = IMG_Load(temp.c_str());
    std::string c;
    if (chuoi[a]==1) c="vua.png";
    else if (chuoi[a]==2) c="nam.png";
    else if (chuoi[a]==3) c="nu.png";
    nhanvat = IMG_Load(c.c_str());
    posCauhoi = {35,129,654,264};
    posTraloiA = {92,418,234,124};
    posTraloiB = {398,418,234,124};
    posNhanvat = {720,129,269,413};
    sttSukien = a;
};

Sukien::~Sukien(){
    SDL_FreeSurface(cauhoi);
    SDL_FreeSurface(traloiA);
    SDL_FreeSurface(traloiB);
    SDL_FreeSurface(nhanvat);
    posCauhoi = {0,0,0,0};
    posTraloiA = {0,0,0,0};
    posTraloiB = {0,0,0,0};
    posNhanvat = {0,0,0,0};
    sttSukien = 0;
};

void show(Sukien a) {
    texture=SDL_CreateTextureFromSurface(renderer,a.cauhoi);
    SDL_RenderCopy(renderer,texture,NULL,&a.posCauhoi);
    texture=SDL_CreateTextureFromSurface(renderer,a.traloiA);
    SDL_RenderCopy(renderer,texture,NULL,&a.posTraloiA);
    texture=SDL_CreateTextureFromSurface(renderer,a.traloiB);
    SDL_RenderCopy(renderer,texture,NULL,&a.posTraloiB);
    texture=SDL_CreateTextureFromSurface(renderer,a.nhanvat);
    SDL_RenderCopy(renderer,texture,NULL,&a.posNhanvat);
    SDL_RenderPresent(renderer);
};

void explain(Sukien a, bool b) {
    SDL_RenderClear(renderer);
    game::showNen(khungNen);
    game::showAttributes();
    std::string c = 'd'+std::to_string(a.sttSukien);
    (b)?c+='b':c+='a';
    c+=".png";
    texture=IMG_LoadTexture(renderer,c.c_str());
    SDL_RenderCopy(renderer,texture,NULL,&a.posCauhoi);
    SDL_RenderPresent(renderer);
}

void Sukien::thaydoi(short a) {
    std::string b = std::to_string(this->sttSukien)+".txt";
    std::ifstream input(b);
    short temp1; char temp2;
    do {input>>temp1;} while (temp1!=a);
    do {
        if (input.eof()) break;
        input>>temp1;
        if (temp1==200) break;
        input>>temp2;
        game::thaydoithuoctinh(temp2, temp1);
    } while (true);
    input.close();
}
