#ifndef VARIABLES_H
#define VARIABLES_H

#include "Everythings.h"

//Environment variables
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* texture = NULL;
Mix_Music* music = NULL;
Mix_Chunk* chunk = NULL;
SDL_Event event;

//Game-needed variables
bool isRunning = true;
bool isLocking = false;
int const WIDTH = 1024;
int const HEIGHT = 576;

//Self-game variables
short bgNumber = 0;
short endNumber = 0;
short turn = 0;
short characterList[30] = {2,1,3,4,1,1,5,1,1,4,6,1,1,7,1,8,7,9,1,5,1,6,1,6,10,4,5,7,1,3};
bool collection[4] = {0,0,0,0};
short branchNumber = 0;
bool eventCheck[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
gameEvent game_event;

//Attributes
short Money = 32;
short Favor = 32;
short Oxygen = 64;
short Influ = 32;
short Trans = 32;

#endif