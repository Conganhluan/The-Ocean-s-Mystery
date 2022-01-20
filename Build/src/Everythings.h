#ifndef EVERYTHINGS_H
#define EVERYTHINGS_H

#include <SDL.h>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

//Environment variables
extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Texture* texture;
extern Mix_Music* bgMusic;
extern SDL_Event event;

//Game-needed variables
extern bool isRunning;
extern bool isLocking;

//Self-game variables
extern short bgNumber;
extern short endNumber;
extern short turn;
extern short character[30];
extern bool collection[4];

//Attributes
extern short Money;
extern short Favor;
extern short Oxygen;
extern short Influ;
extern short Trans;

#endif