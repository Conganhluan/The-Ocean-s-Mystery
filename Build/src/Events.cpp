#include"Events.h"

Sukien::Sukien(short a){
    std::string b = std::to_string(a);
    cauhoi = 'c'+b+".png";
    traloiA = 'a'+b+".png";
    traloiB = 'b'+b+".png";
    if (chuoi[a]==1) nhanvat="vua.png";
    else if (chuoi[a]==2) nhanvat="nam.png";
    else if (chuoi[a]==3) nhanvat="nu.png";
    posCauhoi = {35,129,654,264};
    posTraloiA = {92,418,234,124};
    posTraloiB = {398,418,234,124};
    posNhanvat = {720,129,269,413};
    sttSukien = a;
};

Sukien::Sukien(){
    nhanvat=traloiA=cauhoi=traloiB="";
    posCauhoi = {0,0,0,0};
    posTraloiA = {0,0,0,0};
    posTraloiB = {0,0,0,0};
    posNhanvat = {0,0,0,0};
    sttSukien=-1;
}

Sukien::~Sukien(){
    nhanvat=traloiA=cauhoi=traloiB="";
    posCauhoi = {0,0,0,0};
    posTraloiA = {0,0,0,0};
    posTraloiB = {0,0,0,0};
    posNhanvat = {0,0,0,0};
    sttSukien=-1;
};

void show(Sukien a) {
    texture=IMG_LoadTexture(renderer,a.cauhoi.c_str());
    SDL_RenderCopy(renderer,texture,NULL,&a.posCauhoi);
    texture=IMG_LoadTexture(renderer,a.traloiA.c_str());
    SDL_RenderCopy(renderer,texture,NULL,&a.posTraloiA);
    texture=IMG_LoadTexture(renderer,a.traloiB.c_str());
    SDL_RenderCopy(renderer,texture,NULL,&a.posTraloiB);
    texture=IMG_LoadTexture(renderer,a.nhanvat.c_str());
    SDL_RenderCopy(renderer,texture,NULL,&a.posNhanvat);
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
    SDL_Delay(5000);
}

void Sukien::thaydoi(short a) {
    std::string b = std::to_string(sttSukien)+".txt";
    std::ifstream input(b.c_str());
    std::string luachon;
    short temp1; char temp2;
    do {input>>luachon;} while (luachon!=std::to_string(a));
    while (true) {
        if (input.eof()) break;
        input>>temp1;
        if (temp1==200) break;
        input>>temp2;
        game::thaydoithuoctinh(temp2, temp1);
    };
    input.close();
}

void Sukien::getDulieu(short a) {
    std::string b = std::to_string(a);
    cauhoi = 'c'+b+".png";
    traloiA = 'a'+b+".png";
    traloiB= 'b'+b+".png";
    if (chuoi[a]==1) nhanvat="vua.png";
    else if (chuoi[a]==2) nhanvat="nam.png";
    else if (chuoi[a]==3) nhanvat="nu.png";
    posCauhoi = {35,129,654,264};
    posTraloiA = {92,418,234,124};
    posTraloiB = {398,418,234,124};
    posNhanvat = {720,129,269,413};
    sttSukien = a;
}

short Sukien::laySTT(){
    return sttSukien;
}