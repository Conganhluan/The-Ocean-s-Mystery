#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Everythings.h"

//Update the attributes
void game::updateAttributes(char attribute, short number) {
    switch (attribute) {
        case 'M': 
            Money+=number;
            if (Money>=64) {
                Money=64;
                endNumber=1;
            }
            else if (Money<=0) {
                Money=0;
                endNumber=2;
            }
            break;
        case 'F':
            Favor+=number;
            if (Favor>=64) {
                Favor=64;
                endNumber=3;
            }
            else if (Favor<=0) {
                Favor=0;
                endNumber=4;
            }
            break;
        case 'O':
            Oxygen+=number;
            if (Oxygen>64) Oxygen=64;
            else if (Oxygen<=0) {
                Oxygen=0;
                endNumber=5;
            }
            break;
        case 'I':
            Influ+=number;
            if (Influ>=64) {
                Influ=64;
                endNumber=6;
            }
            else if (Influ<=0) {
                Influ=0;
                endNumber=7;
            }
            break;
        case 'T':
            Trans+=number;
            if (Trans>=64) {
                Trans=64;
                endNumber=8;
            }
            else if (Trans<0) {
                Trans=0;
                endNumber=9;
            }
    }
    return;
}

//Update the attributes regularly after each turn
void game::updateStatus(short option) {
    Oxygen-=12;
    switch (option) {
        case 1:
            Money-=8;
            Favor+=8;
            break;
        case 2:
            Favor-=8;
            Trans+=8;
            break;
        case 3:
            Influ-=8;
            Money+=8;
            break;
        case 4:
            Trans-=8;
            Influ+=8;
            break;

    }
    return;
}

//Return a random number from 0 to 29
short game::getRandom() {
    srand(time(NULL));
    return rand()%30;
}

//Get the attributes to the renderer
void game::showAttributes() {
    game::showBg(bgNumber);
    texture = IMG_LoadTexture(renderer,"resource/favor.png");
    SDL_Rect temp = {0,64-Favor,64,Favor};
    SDL_Rect temp2 = {305,104-Favor,64,Favor};
    SDL_RenderCopy(renderer,texture,&temp,&temp2);

    texture = IMG_LoadTexture(renderer,"resource/influ.png");
    temp = {0,64-Influ,64,Influ};
    temp2 = {431,105-Influ,64,Influ};
    SDL_RenderCopy(renderer,texture,&temp,&temp2);

    texture = IMG_LoadTexture(renderer,"resource/money.png");
    temp = {0,64-Money,64,Money};
    temp2 = {40,105-Money,64,Money};
    SDL_RenderCopy(renderer,texture,&temp,&temp2);

    texture = IMG_LoadTexture(renderer,"resource/oxygen.png");
    temp = {0,64-Oxygen,64,Oxygen};
    temp2 = {164,104-Oxygen,64,Oxygen};
    SDL_RenderCopy(renderer,texture,&temp,&temp2);

    texture = IMG_LoadTexture(renderer,"resource/trans.png");
    temp = {0,64-Trans,64,Trans};
    temp2 = {555,105-Trans,64,Trans};
    SDL_RenderCopy(renderer,texture,&temp,&temp2);
    return;
}

//Get the information from the file Cache.txt
void game::inCache() {
    std::ifstream input("resource/Cache.txt",std::ios::in);
    for (int i=0;i<30;i++) input>>eventCheck[i];
    for (int i=0;i<4;i++) input>>collection[i];
    input>>Money>>Favor>>Oxygen>>Influ>>Trans>>branchNumber>>turn;
    input.close();
    return;
}

//Update the information to the file Cache.txt
void game::outCache() {
    std::ofstream output("resource/Cache.txt",std::ios::out);
    for (int i=0;i<6;i++) {
        for (int j=0;j<5;j++) output<<eventCheck[i*5+j]<<" ";
        output<<std::endl;
    }
    for (int i=0;i<4;i++) output<<collection[i]<<" ";
    output<<std::endl;
    output<<Money<<" ";
    output<<Favor<<" ";
    output<<Oxygen<<" ";
    output<<Influ<<" ";
    output<<Trans<<std::endl;
    output<<branchNumber<<" "<<turn;
    output.close();
    return;
}

//Get the collection to the renderer
void game::showCollection() {
    game::showBg(bgNumber);
    SDL_Rect rect0 = {312,120,200,200};
    SDL_Rect rect1 = {522,120,200,200};
    SDL_Rect rect2 = {312,330,200,200};
    SDL_Rect rect3 = {522,330,200,200};
    if (collection[0]) {
        texture = IMG_LoadTexture(renderer,"resource/collection0.png");
        SDL_RenderCopy(renderer,texture,NULL,&rect0);
    }
    if (collection[1]) {
        texture = IMG_LoadTexture(renderer,"resource/collection1.png");
        SDL_RenderCopy(renderer,texture,NULL,&rect1);
    }
    if (collection[2]) {
        texture = IMG_LoadTexture(renderer,"resource/collection2.png");
        SDL_RenderCopy(renderer,texture,NULL,&rect2);
    }
    if (collection[3]) {
        texture = IMG_LoadTexture(renderer,"resource/collection3.png");
        SDL_RenderCopy(renderer,texture,NULL,&rect3);
    }
    return;
}

//Get the background to the renderer
void game::showBg(short bgNumber) {
    SDL_RenderClear(renderer);
    std::string temp = "resource/bg"+std::to_string(bgNumber)+".png";
    texture = IMG_LoadTexture(renderer,temp.c_str());
    SDL_RenderCopy(renderer,texture,NULL,NULL);
    return;
}

//Get stories to the renderer
void game::showStory(short branch, short turn) {
    SDL_RenderClear(renderer);
    std::string temp = "resource/stories/story"+std::to_string(branch)+"_"+std::to_string(turn)+".png";
    texture = IMG_LoadTexture(renderer,temp.c_str());
    SDL_RenderCopy(renderer,texture,NULL,NULL);
    return;
}

//Set all relevant variables to Starting status
void game::setUp() {
    bgNumber = 1;
    endNumber = 0;
    turn = 0;
    branchNumber = 0;
    memset(eventCheck,false,30);
    Money = 32;
    Favor = 32;
    Oxygen = 64;
    Influ = 32;
    Trans = 32;
    return;
}

//Get endings to the renderer
void game::showEnding(short number) {
    SDL_RenderClear(renderer);
    std::string temp = "resource/stories/end"+std::to_string(number)+".png";
    texture = IMG_LoadTexture(renderer,temp.c_str());
    SDL_RenderCopy(renderer,texture,NULL,NULL);
    return;
}

//Get the normal events' information to the renderer
void showEvent(gameEvent a) {
    game::showAttributes();
    SDL_Rect temp1 = {35,129,654,264};
    SDL_Rect temp2 = {92,418,234,124};
    SDL_Rect temp3 = {398,418,234,124};
    SDL_Rect temp4 = {720,129,269,413};
    texture = IMG_LoadTexture(renderer,a.situation.c_str());
    SDL_RenderCopy(renderer,texture,NULL,&temp1);
    texture = IMG_LoadTexture(renderer,a.answerA.c_str());
    SDL_RenderCopy(renderer,texture,NULL,&temp2);
    texture = IMG_LoadTexture(renderer,a.answerB.c_str());
    SDL_RenderCopy(renderer,texture,NULL,&temp3);
    texture = IMG_LoadTexture(renderer,a.character.c_str());
    SDL_RenderCopy(renderer,texture,NULL,&temp4);
    return;
}

//Get the explain for the event to the renderer
void explainEvent(gameEvent a, bool right) {
    game::showAttributes();
    std::string temp = "resource/events/d"+std::to_string(a.getNumber());
    (right)?temp+='b':temp+='a';
    temp+=".png";
    SDL_Rect temp1 = {35,129,654,264};
    SDL_Rect temp2 = {720,129,269,413};
    texture = IMG_LoadTexture(renderer,temp.c_str());
    SDL_RenderCopy(renderer,texture,NULL,&temp1);
    texture = IMG_LoadTexture(renderer,a.character.c_str());
    SDL_RenderCopy(renderer,texture,NULL,&temp2);
    return;
}

//Press left button of the mouse to continue
void game::press() {
    isLocking = true;
    while (isLocking) if (SDL_PollEvent(&event)!=0) {
        if (event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT)
        isLocking = false;
    }
    return;
}

//Get the introductions to the renderer
void game::showIntroduction(short number) {
    SDL_RenderClear(renderer);
    std::string temp = "resource/stories/intro"+std::to_string(number)+".png";
    texture = IMG_LoadTexture(renderer,temp.c_str());
    SDL_RenderCopy(renderer,texture,NULL,NULL);
    return;
}

//Update the new branch
bool game::updateBranch() {
    short maxx = 0, maxxx;
    if (maxx<Money) {
        maxxx = 1;
        maxx = Money;
    }
    if (maxx<Favor) {
        maxxx = 2;
        maxx = Favor;
    }
    if (maxx<Influ) {
        maxxx = 3;
        maxx = Influ;
    }
    if (maxx<Trans) {
        maxxx = 4;
        maxx = Trans;
    }
    switch (turn) {
        case 5:
            branchNumber = maxxx;
            return true;
        case 10: 
            switch (branchNumber) {
                case 1:
                    if (maxxx==1 || maxxx==2) return false;
                    break;
                case 2:
                    if (maxxx==2 || maxxx==4) return false;
                    break;
                case 3:
                    if (maxxx==3 || maxxx==1) return false;
                    break;
                case 4:
                    if (maxxx==4 || maxxx==3) return false;
                    break;
            }
            break;
        case 15:
            branchNumber = maxxx;
            return true;
    }
    return true;
}

//Notice the END of the game for the player
void game::startOver() {
    SDL_RenderClear(renderer);
    texture = IMG_LoadTexture(renderer,"resource/stories/startover.png");
    SDL_RenderCopy(renderer,texture,NULL,NULL);
    return;
}

#endif