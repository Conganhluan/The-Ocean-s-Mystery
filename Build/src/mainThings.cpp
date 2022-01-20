#include"mainThings.h"

void game::thaydoithuoctinh(char a, short b) {
    switch (a) {
        case 'M': 
            Money+=b;
            if (Money>=64) {
                Money=64;
                ketThuc=1;
            }
            else if (Money<=0) {
                Money=0;
                ketThuc=2;
            }
            break;
        case 'F':
            Favor+=b;
            if (Favor>=64) {
                Favor=64;
                ketThuc=3;
            }
            else if (Favor<=0) {
                Favor=0;
                ketThuc=4;
            }
            break;
        case 'O':
            Oxygen+=b;
            if (Oxygen>64) Oxygen=64;
            else if (Oxygen<=0) {
                Oxygen=0;
                ketThuc=5;
            }
            break;
        case 'I':
            Influ+=b;
            if (Influ>=64) {
                Influ=64;
                ketThuc=6;
            }
            else if (Influ<=0) {
                Influ=0;
                ketThuc=7;
            }
            break;
        case 'T':
            Trans+=b;
            if (Trans>=64) {
                Trans=64;
                ketThuc=8;
            }
            else if (Trans<0) Trans=0;
    }
};

void game::bienDoi(){
    thaydoithuoctinh('O',-16);
    thaydoithuoctinh('T',+8);
};

void game::showNen(int a) {;
    SDL_RenderClear(renderer);
    std::string temp = "nen"+std::to_string(a)+".png";
    texture = IMG_LoadTexture(renderer,temp.c_str());
    SDL_RenderCopy(renderer,texture,NULL,NULL);
};

short game::layRandom(){
    srand(time(NULL));
    return (short)rand()%20;
}

void game::nhapfileCache(){
    std::ifstream input("Cache.txt");
    for (int i=0;i<30;i++) input>>stt[i];
    for (int i=0;i<4;i++) input>>collection[i];
    input>>turn>>Money>>Favor>>Oxygen>>Influ>>Trans>>Checkpoint>>reNhanh;
    input.close();
}

void game::xuatfileCache(){
    std::ofstream output("Cache.txt",std::ios::out);
    for (int i=0;i<30;i++) output<<stt[i]<<std::endl;
    for (int i=0;i<4;i++) output<<collection[i]<<std::endl;
    output<<turn<<std::endl<<Money<<std::endl<<Favor<<std::endl<<Oxygen<<std::endl<<Influ<<std::endl<<Trans<<std::endl<<Checkpoint<<std::endl<<reNhanh;
    output.close();
}

void game::inKetthuc(short a) {
    SDL_RenderClear(renderer);
    std::string temp = "end"+std::to_string(a)+".png";
    texture = IMG_LoadTexture(renderer,temp.c_str());
    SDL_RenderCopy(renderer,texture,NULL,NULL);
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);
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
    std::string c = "sukien"+std::to_string((int)a) +std::to_string((int)b)+".png";
    texture = IMG_LoadTexture(renderer,c.c_str());
    SDL_Rect pos = {35,129,654,264};
    SDL_RenderCopy(renderer,texture,NULL,&pos);
}

void game::inLoigioithieu(){
    SDL_RenderClear(renderer);
    texture = IMG_LoadTexture(renderer,"loigioithieu.png");
    SDL_RenderCopy(renderer,texture,NULL,NULL);
    SDL_RenderPresent(renderer);
}

void game::setupAttribute(){
    Money = 32;
    Favor = 32;
    Oxygen = 64;
    Trans = 0;
    Influ = 15;
    turn = 0;
}