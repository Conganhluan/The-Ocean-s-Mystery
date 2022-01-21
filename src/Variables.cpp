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
int const WIDTH = 1024;
int const HEIGHT = 576;

//Self-game variables
short bgNumber = 0;
short endNumber = 0;
short turn = 0;
short characterList[30] = {};
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