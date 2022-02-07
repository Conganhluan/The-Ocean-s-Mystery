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
extern Mix_Chunk* chunk;
extern SDL_Event event;

//Game-needed variables
extern bool isRunning;
extern bool isLocking;
extern const int WIDTH;
extern const int HEIGHT; 

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

//Functions for game
namespace game {
    void updateAttributes(char attribute, short number);
    void updateStatus(short option);
    short getRandom();
    void showBg(short bgNumber);
    void showAttributes();
    void inCache();
    void outCache();
    void showCollection();
    void showStory(short branch, short turn);
    void setUp();
    void showEnding(short number);
    void press();
    void showIntroduction(short number);
    bool updateBranch();
    void startOver();
    void soundClick(std::string name);
}

namespace gameCase {
    void welcomeCase();
    void mainCase();
    void creditCase();
    void collectionCase();
    void storyCase();
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
        friend void explainEvent(gameEvent a, bool right);
};

extern gameEvent game_event;

#endif