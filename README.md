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
- 8: Intransformation>=64.
- 9: Intransformation<=0.
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
- Situation: c*number*.png;
- AnswerA: a*number*.png;
- AnswerB: b*number*.png;
- ExplainA: d*number*a.png;
- ExplainB: d*number*b.png;
- Attribute_change: *number*.txt;
## Stories' files (in resource/stories/):
- Stories' files: story*branch*_*turn*.png;
- Endings' files: end*number*.png;   
- Introducions' files: intro*number*.png;
## Sounds' files (in resource/sounds/):
- Background music: bgmusic.mp3;
- Interactive sound: *name*.wav;
## Another files (in resource/):
- Characters' files: *Character's name*.png;
- Atrributes' files: *Atrribute's name*.png;
- Collections' files: collection*number*.png;
- Backgrounds' files: bg*number*.png;
- Cache file: Cache.txt;


# .txt files' formats:
## Cache file:
- The 6 first rows (each row has 5 number) is eventCheck[].
- The 7th row is collectionList[].
- The 8th row sequencely are Money, Favor, Oxygen, Influence, Transformation.
- The 9th row sequencely are branchNumber, turn and isSaved.
## Attribute_change files: 
100 *number* *uppercase_first_letter_of_attribute* *number* *uppercase_first_letter_of_attribute* ...  
> This line is for the answerA.  
  
200 *number* *uppercase_first_letter_of_attribute* *number* *uppercase_first_letter_of_attribute* ...  
> This line is for the answerB.