#include"mainThings.h"

void game::thaydoithuoctinh(char a, short b) {
    switch (a) {
        case 'M': 
            Money+=b;
            if (Money>=100) ketThuc=1;
            else if (Money<=0) ketThuc=2;
            break;
        case 'F':
            Favor+=b;
            if (Favor>=100) ketThuc=3;
            else if (Favor<=0) ketThuc=4;
            break;
        case 'O':
            Oxygen+=b;
            if (Oxygen>100) Oxygen=100;
            else if (Oxygen<=0) ketThuc=5;
            break;
        case 'I':
            Influ+=b;
            if (Influ>=100) ketThuc=6;
            else if (Influ<=0) ketThuc=7;
            break;
        case 'T':
            Trans+=b;
            if (Trans>=100) ketThuc=8;
            else if (Trans<0) Trans=0;
    }
};

void game::bienDoi(){
    thaydoithuoctinh('O',-10);
    thaydoithuoctinh('T',5);
};

void game::showNen(int a) {
    SDL_RenderClear(renderer);
    std::string temp = "nen"+std::to_string(a)+".png";
    texture = IMG_LoadTexture(renderer,temp.c_str());
    SDL_RenderCopy(renderer,texture,NULL,NULL);
    SDL_RenderPresent(renderer);
};

int game::layRandom(){
    srand(time(NULL));
    return rand()%30;
}