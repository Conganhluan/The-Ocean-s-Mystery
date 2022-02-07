The game is about the adventure to get out of the Life under the Ocean.
Besides and most important is to find inserts to complete the Collection which reveals the Truth there.


# Variables:
## bgNumber:
- 0: The starting background.
- 1: The starting background with the continue button.
- 2: The main background to play the game.
- 3: The main background 2 to play the game (darker background).
- 4: The credit background.
- 5: The collection background.
- 6: The background to show the introductions, stories and endings.
## gameCase:
- welcomeCase(): bgNumber 0 and 1.    
- mainCase(): bgNumber 2 and 3.
- creditCase(): bgNumber 4.
- collectionCase(): bgNumber 5.
- storyCase(): bgNumber 6.
## endNumber:
- 0: Not end yet.
- 1: Money>=64.
- 2: Money<=0.
- 3: Favor>=64.
- 4: Favor<=0.
- 5: Oxygen<=0.
- 6: Influence>=64.
- 7: Influende<=0.
- 8: Transformation>=64.
- 9: Transformation<=0.
- 10: Complete branch 1.
- 11: Complete branch 2.
- 12: Complete branch 3.
- 13: Complete branch 4.
- 14: Uncomplete mission.
## charaterList:
each member is the character number for events.
## branchNumber:
- 0: Not a branch yet.
- 1: Depend on Money.
- 2: Depend on Favor.
- 3: Depend on Influence.
- 4: Depend on Transformation.


# File names:
## Events' files (in resource/events/):
- Situation: c*number*.png; (654x264*px*)
- AnswerA: a*number*.png; (234x124*px*)
- AnswerB: b*number*.png; (234x124*px*)
- ExplainA: d*number*a.png; (654x264*px*)
- ExplainB: d*number*b.png; (654x264*px*)
- Attribute_change: event*number*.txt;
## Stories' files (in resource/stories/):
- Stories' files: story*branch*_*turn*.png; (1024x576*px*)
- Endings' files: end*number*.png; (1024x576*px*)
- Introducions' files: intro*number*.png; (1024x576*px*)
- StartOver's file: startover.png; (1024x576*px*)
## Sounds' files (in resource/sounds/):
- Background music: bgmusic.mp3;
- Interactive sound: *name*.wav;
## Another files (in resource/):
- Characters' files: *Character's name*.png; (260x400*px*)
- Atrributes' files: *Atrribute's name*.png; (64x64*px*)
- Collections' files: collection*number*.png; (200x200*px*)
- Backgrounds' files: bg*number*.png; (1024x576*px*)
- Cache file: Cache.txt;


# .txt files' formats:
## Cache file:
- The 6 first rows (each row has 5 number) is eventCheck[].
- The 7th row is collectionList[].
- The 8th row sequencely are Money, Favor, Oxygen, Influence, Transformation.
- The 9th row sequencely are branchNumber, turn and isSaved.
## Attribute_change files: 
event*number*  
100 *number* *uppercase_first_letter_of_attribute* *number* *uppercase_first_letter_of_attribute* ...  
> This line is for the answerA.  
  
200 *number* *uppercase_first_letter_of_attribute* *number* *uppercase_first_letter_of_attribute* ...  
> This line is for the answerB.  

# Command to compile in Luan's PC
"C:\Program Files\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\g++.exe" -g src\main.cpp -o build\game.exe -ID:/Personal_files/C++/The-Ocean-s-Mystery/lib/SDL/SDL2-2.0.20/include -LD:/Personal_files/C++/The-Ocean-s-Mystery/lib/SDL/SDL2-2.0.20/lib/x64 -Wall -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -mwindows