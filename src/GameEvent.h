#ifndef GAMEEVENT_H
#define GAMEEVENT_H

#include "Everythings.h"

//Initialize a gameEvent
gameEvent::gameEvent() {
    situation=answerB=answerA=explainA=explainB=character="";
    number=0;
}

//Destroy a gameEvent
gameEvent::~gameEvent() {
    situation=answerB=answerA=explainA=explainB=character="";
    number=0;
}

//Create an event with the new number
void gameEvent::setNumber(short a) {
    std::string temp = std::to_string(a);
    situation = "resource/events/c"+temp+".png";
    answerA = "resource/events/a"+temp+".png";
    answerB = "resource/events/b"+temp+".png";
    explainA = "resource/events/d"+temp+"a.png";
    explainB = "resource/events/d"+temp+"b.png";
    character = "resource/";
    switch (characterList[a]) {
        case 1:
            character+="king";
            break;
        case 2:
            character+="cave";
            break;
        case 3:
            character+="prophet";
            break;
        case 4:
            character+="lady";
            break;
        case 5:
            character+="queen";
            break;
        case 6:
            character+="physician";
            break;
        case 7:
            character+="man";
            break;
        case 8:
            character+="cook";
            break;
        case 9:
            character+="festival";
            break;
        case 10:
            character+="coinbag";
            break;
    }
    character+=".png";
    number = a;
    return;
}

//Get the number of the event
short gameEvent::getNumber() {
    return number;
}

//Change the attribute status according to player's option
void gameEvent::changeAttributes(bool right) {
    std::string nameEvent = "resource/events/event"+std::to_string(number)+".txt";
    std::ifstream input(nameEvent.c_str());
    std::string option, choice;
    short temp1;
    char temp2;
    (right)?choice="200":choice="100";
    do {input>>option;} while (option!=choice);
    while (true) {
        if (input.eof()) break;
        input>>temp1;
        if (temp1==200) break;
        input>>temp2;
        game::updateAttributes(temp2,temp1);
    };
    input.close();
    return;
}

#endif