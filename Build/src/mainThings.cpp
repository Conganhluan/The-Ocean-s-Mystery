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
    nenHientai=khungNen;
};

short game::layRandom(){
    srand(time(NULL));
    return (short)rand()%20;
}

void game::nhapfileCache(){
    std::ifstream input("Cache.txt");
    for (int i=0;i<30;i++) input>>stt[i];
    for (int i=0;i<4;i++) input>>collection[i];
    input>>turn>>Money>>Favor>>Oxygen>>Influ>>Trans>>Save>>reNhanh;
    input.close();
}

void game::xuatfileCache(){
    std::ofstream output("Cache.txt",std::ios::out);
    for (int i=0;i<30;i++) output<<stt[i]<<std::endl;
    for (int i=0;i<4;i++) output<<collection[i]<<std::endl;
    output<<turn<<std::endl<<Money<<std::endl<<Favor<<std::endl<<Oxygen<<std::endl<<Influ<<std::endl<<Trans<<std::endl<<Save<<std::endl<<reNhanh;
    output.close();
}

void game::inCredit(){
    texture = IMG_LoadTexture(renderer,"credit.png");
    SDL_RenderCopy(renderer,texture,NULL,NULL);
    SDL_RenderPresent(renderer);
}

void game::inKetthuc(short a) {
    std::string temp = "end"+std::to_string(a)+".png";
    texture = IMG_LoadTexture(renderer,temp.c_str());
    SDL_RenderCopy(renderer,texture,NULL,NULL);
    SDL_RenderPresent(renderer);
    SDL_Delay(10000);
    khungNen=5;
}

void game::inCollection() {
    SDL_Rect rect0 = {312,120,200,200};
    SDL_Rect rect1 = {522,120,200,200};
    SDL_Rect rect2 = {312,330,200,200};
    SDL_Rect rect3 = {522,330,200,200};
    if (collection[0]) {
        texture = IMG_LoadTexture(renderer,"collection0.png");
        SDL_RenderCopy(renderer,texture,NULL,&rect0);
    }
    if (collection[1]) {
        texture = IMG_LoadTexture(renderer,"collection1.png");
        SDL_RenderCopy(renderer,texture,NULL,&rect1);
    }
    if (collection[2]) {
        texture = IMG_LoadTexture(renderer,"collection2.png");
        SDL_RenderCopy(renderer,texture,NULL,&rect2);
    }
    if (collection[3]) {
        texture = IMG_LoadTexture(renderer,"collection3.png");
        SDL_RenderCopy(renderer,texture,NULL,&rect3);
    }
    SDL_RenderPresent(renderer);
}

void game::inSukien(short a, short b){
    std::string c = "sukien"+std::to_string(a) +std::to_string(b)+".png";
    texture = IMG_LoadTexture(renderer,c.c_str());
    SDL_Rect pos = {35,129,654,264};
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,texture,NULL,&pos);
    SDL_RenderPresent(renderer);
}

void game::inLoigioithieu(){
    SDL_RenderClear(renderer);
    texture = IMG_LoadTexture(renderer,"loigioithieu.png");
    SDL_RenderCopy(renderer,texture,NULL,NULL);
    SDL_RenderPresent(renderer);
}