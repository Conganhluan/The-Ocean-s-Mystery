#include"Attributes.h"

void game::napAttributes(){
    att1 = IMG_Load("att1.png");
    att2 = IMG_Load("att2.png");
    att3 = IMG_Load("att3.png");
    att4 = IMG_Load("att4.png");
    att5 = IMG_Load("att5.png");
}


void game::showAttributes(){
    SDL_Rect temp = {0,64-Favor,64,Favor};
    SDL_Rect temp2 = {41,121-Favor,64,Favor};
    texture = SDL_CreateTextureFromSurface(renderer,att3);
    SDL_RenderCopy(renderer,texture,&temp,&temp2);

    texture = SDL_CreateTextureFromSurface(renderer,att4);
    temp = {0,64-Influ,64,Influ};
    temp2 = {184,121-Influ,64,Influ};
    SDL_RenderCopy(renderer,texture,&temp,&temp2);

    texture = SDL_CreateTextureFromSurface(renderer,att1);
    temp = {0,64-Money,64,Money};
    temp2 = {327,121-Money,64,Money};
    SDL_RenderCopy(renderer,texture,&temp,&temp2);

    texture = SDL_CreateTextureFromSurface(renderer,att2);
    temp = {0,64-Oxygen,64,Oxygen};
    temp2 = {470,121-Oxygen,64,Oxygen};
    SDL_RenderCopy(renderer,texture,&temp,&temp2);

    texture = SDL_CreateTextureFromSurface(renderer,att5);
    temp = {0,64-Trans,64,Trans};
    temp2 = {613,121-Trans,64,Trans};
    SDL_RenderCopy(renderer,texture,&temp,&temp2);
}


void game::xoaAttributes(){
    SDL_FreeSurface(att1);
    SDL_FreeSurface(att2);
    SDL_FreeSurface(att3);
    SDL_FreeSurface(att4);
    SDL_FreeSurface(att5);
}


