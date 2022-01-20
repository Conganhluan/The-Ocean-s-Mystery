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
#include <iostream>

//Environment variables
extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Texture* texture;
extern Mix_Music* music;
extern SDL_Event event;

//Game-needed variables
extern bool isRunning;
extern bool isLocking;

//Self-game variables
extern short bgNumber;
extern short endNumber;
extern short turn;
extern short characterList[30];
extern bool collection[4];
extern short branchNumber;
extern bool eventCheck[30];

//Attributes
extern short Money;
extern short Favor;
extern short Oxygen;
extern short Influ;
extern short Trans;

//Function for game
namespace game {
    void updateAttributes(char attribute, short number);
    void updateStatus();
    short getRandom();
    void showBg(short bgNumber);
    void showAttributes();
    void inCache();
    void outCache();
    void showCollection();
    void showStory(short branch, short turn);
    void setUp();
}

//class gameEvent
class gameEvent {
    private:
        std::string situation;
        std::string answerA;
        std::string answerB;
        std::string character;
        std::string explainA;
        std::string explainB;
        short number;
    public:
        gameEvent();
        ~gameEvent();
        void setNumber(short a);
        short getNumber();
        void changeAttributes(bool right);
        friend void showEvent(gameEvent a);
        friend void explainEvent(gameEvent a, short b);
};

#endif