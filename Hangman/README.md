# Hangman

## Game play understanding
Create the program Hangman. Prompt the player to enter a phrase.
That phrase will be hidden by a series of dashes (excluding spaces).
The player can then guess letters. If they guess correctly all the letters that match will be revealed.
If they guess incorrectly, then 1 more body part will be added to the gallows.
If they lose the gallows should look like this:

``` cpp
 +---+
 |   |
 |   o
 |  /|\
 |  / \
-+-
```

If the player looses, the word should be revealed.
After the game is over the player should be prompted if they want to play again.