#ifndef GAMECASE_H
#define GAMECASE_H

#include "Everythings.h"
using namespace game;

//For the Main Menu screen
void gameCase::welcomeCase() {
    showBg(bgNumber);
    SDL_RenderPresent(renderer);
    isLocking = true;
    while (isLocking) if (SDL_PollEvent(&event)!=0) {
        switch (event.type) {
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.x>443 && event.button.x<583 && event.button.y>197 && event.button.y<277) {
                    setUp();
                    bgNumber = 6;
                    soundClick("right");
                }
                else if (event.button.x>443 && event.button.x<583 && event.button.y>284 && event.button.y<364 && bgNumber==1) {
                    if (turn>=10) bgNumber = 3;
                    else bgNumber = 2;
                    soundClick("right");
                }
                else if (event.button.x>443 && event.button.x<583 && event.button.y>370 && event.button.y<450) {
                    bgNumber = 4;
                    soundClick("right");
                }
                else if (event.button.x>443 && event.button.x<583 && event.button.y>457 && event.button.y<537) {
                    bgNumber = 5;
                    soundClick("right");
                }
                else soundClick("wrong");
                break;
            case SDL_QUIT:
                isRunning = false;
                break;
        }
        if (bgNumber>1 || !isRunning) isLocking = false;
    }
    return;
}

//For the Gameplay screen
void gameCase::mainCase() {
    do {game_event.setNumber(getRandom());} while (eventCheck[game_event.getNumber()]);
    eventCheck[game_event.getNumber()] = true;
    showEvent(game_event);
    SDL_RenderPresent(renderer);
    isLocking = true;
    while (isLocking) {
        bool right, pressOption = false;
        if (SDL_PollEvent(&event)!=0) {
            switch (event.type) {
                case SDL_MOUSEBUTTONDOWN: 
                    if (event.button.x>92 && event.button.x<326 && event.button.y>418 && event.button.y<542) {
                        pressOption = true;
                        right = false;
                        soundClick("right");
                    }
                    else if (event.button.x>398 && event.button.x<632 && event.button.y>418 && event.button.y<542) {
                        pressOption = true;
                        right = true;
                        soundClick("right");
                    }
                    else if (event.button.x>836 && event.button.x<986 && event.button.y>36 && event.button.y<68) {
                        bgNumber = 5;
                        soundClick("right");
                    }
                    else if (event.button.x>836 && event.button.x<986 && event.button.y>78 && event.button.y<110) {
                        bgNumber = 1;
                        soundClick("right");
                    }
                    else if (event.button.x>736 && event.button.x<800 && event.button.y>37 && event.button.y<101) {
                        bgNumber = 4;
                        soundClick("right");
                    }
                    else soundClick("wrong");
                    if (pressOption) {
                        game_event.changeAttributes(right);
                        if (bgNumber==2) updateStatus(branchNumber);
                        else updateStatus(0);
                        explainEvent(game_event,right);
                        SDL_RenderPresent(renderer);
                        press();
                        turn++;
                        if (endNumber!=0 || turn%5==0) bgNumber = 6;
                    }
                    break;
                case SDL_QUIT:
                    isRunning = false;
                    break;
            }
            if (pressOption || (bgNumber!=2 && bgNumber!=3) || !isRunning) isLocking = false;
        }
    }
    return;
}

//For the Credit screen
void gameCase::creditCase() {
    showBg(bgNumber);
    SDL_RenderPresent(renderer);
    isLocking = true;
    while (isLocking) if (SDL_PollEvent(&event)!=0) {
        if (event.type==SDL_MOUSEBUTTONDOWN) {
            if (event.button.x>47 && event.button.x<197 && event.button.y>57 && event.button.y<89) {
                bgNumber = 1;
                soundClick("right");
            }
            else soundClick("wrong");
        }
        else if (event.type==SDL_QUIT) isRunning = false;
        if (!isRunning || bgNumber!=4) isLocking = false;
    }
    return;
}

//For the Collection screen
void gameCase::collectionCase() {
    showCollection();
    SDL_RenderPresent(renderer);
    isLocking = true;
    while (isLocking) if (SDL_PollEvent(&event)!=0) {
        if (event.type==SDL_MOUSEBUTTONDOWN) {
            if (event.button.x>47 && event.button.x<197 && event.button.y>37 && event.button.y<69) {
                bgNumber = 1;
                soundClick("right");
            }
            else soundClick("wrong");
        }
        else if (event.type==SDL_QUIT) isRunning = false;
        if (bgNumber!=5 || !isRunning) isLocking = false;
    }
    return;
}

//For the Introduction, Story, Ending and Goodbye screen 
void gameCase::storyCase() {
    //Game-over screen
    bool check = true;
    for (int i=0;i<4;i++) if (!collection[i]) {
        check = false;
        break;
    }
    if (check) {
        startOver();
        SDL_RenderPresent(renderer);
        isLocking = true;
        while (isLocking) if (SDL_PollEvent(&event)!=0) {
            switch (event.type) {
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.x>=840 && event.button.x<=990 && event.button.y>=30 && event.button.y<=62) {
                        memset(collection,0,4);
                        bgNumber = 2;
                        soundClick("right");
                    }
                    else if (event.button.x>=30 && event.button.x<=180 && event.button.y>=30 && event.button.y<=62) {
                        bgNumber = 5;
                        soundClick("right");
                    }
                    else soundClick("wrong");
                    break;
                case SDL_QUIT:
                    isRunning = false;
                    break;
            }
            if (bgNumber!=6 || !isRunning) isLocking = false;
        }
    }
    //End-game screen
    else if (endNumber!=0) {
        showEnding(endNumber);
        SDL_RenderPresent(renderer);
        press();
        if (endNumber>=10 && endNumber<=13) collection[endNumber-10] = true;
        showBg(bgNumber);
        SDL_RenderPresent(renderer);
        isLocking = true;
        while (isLocking) if (SDL_PollEvent(&event)!=0) {
            if (event.type==SDL_MOUSEBUTTONDOWN) {
                if (event.button.x>423 && event.button.x<603 && event.button.y>428 && event.button.y<528) {
                    bgNumber = 0;
                    soundClick("right");
                }
                else soundClick("wrong");
            }
            else if (event.type==SDL_QUIT) isRunning = false;
            if (bgNumber!=6 || !isRunning) isLocking = false;
        }
    }
    //Introduction screen
    else if (turn==0) {
        showIntroduction(0);
        SDL_RenderPresent(renderer);
        press();
        if (isRunning) {
            showIntroduction(1);
            SDL_RenderPresent(renderer);
            press();
            bgNumber = 2;
        }
    }
    //Story telling screen
    else {
        if (turn==5) {
            updateBranch();
            showStory(branchNumber,turn);
            SDL_RenderPresent(renderer);
            press();
            bgNumber = 2;
        }
        else if (turn==10) {
            if (updateBranch()) {
                showStory(branchNumber,turn);
                SDL_RenderPresent(renderer);
                press();
                bgNumber = 3;
            }
            else endNumber = 14;
        }
        else if (turn==15) {
            updateBranch();
            endNumber = branchNumber+9;
        }
    }
    return;
}

#endif