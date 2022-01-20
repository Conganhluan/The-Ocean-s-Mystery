#include "Everythings.h"

//Environment variables
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* texture = NULL;
Mix_Music* music = NULL;
SDL_Event event;

//Game-needed variables
bool isRunning = true;
bool isLocking = false;

//Self-game variables
short bgNumber = 1;
short endNumber = 0;
short turn = 0;
short characterList[30] = {};
bool collection[4] = {0,0,0,0};
short branchNumber = 0;
bool eventCheck[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

//Attributes
short Money = 32;
short Favor = 32;
short Oxygen = 64;
short Influ = 16;
short Trans = 0;