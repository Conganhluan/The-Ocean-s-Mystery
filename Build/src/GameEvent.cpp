#include "Everythings.h"

gameEvent::gameEvent() {
    situation=answerB=answerA=explainA=explainB=character="";
    number=0;
}

gameEvent::~gameEvent() {
    situation=answerB=answerA=explainA=explainB=character="";
    number=0;
}

//Create an event with the new number
void gameEvent::setNumber(short a) {
    std::string temp = std::to_string(a);
    situation = "resource/c"+temp+".png";
    answerA = "resource/a"+temp+".png";
    answerB = "resource/b"+temp+".png";
    explainA = "resource/d"+temp+"a.png";
    explainB = "resource/d"+temp+"b.png";
    character = "resource/";
    switch (characterList[a]) {
        case 1:
            character+="king";
            break;
        case 2:
            break;
        default: character+="king";
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
    std::string temp = "resource/"+std::to_string(number)+".txt";
    std::ifstream input(temp.c_str());
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

