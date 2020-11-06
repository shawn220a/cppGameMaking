# Hangman

## Game play understanding

Create the program Hangman. Prompt the player to enter a phrase.
That phrase will be hidden by a series of dashes (excluding spaces).
The player can then guess letters. If they guess correctly all the letters that match will be revealed.
If they guess incorrectly, then 1 more body part will be added to the gallows.
If they lose the gallows should look like this:

```cpp
 +---+
 |   |
 |   o
 |  /|\
 |  / \
-+-
```

If the player looses, the phrase should be revealed.
After the game is over the player should be prompted if they want to play again.

## Pseudocode

- We need a way of storing the secret phrase
- We need a way of storing the hidden phrase (with dashes)
- We need a variable that holds the number of guesses left (set to 6 initially)

```cpp
/*
Step 1
Main
----

do {
  PlayGame();
} while (WantToPlayAgain());

Step 2
PlayGame
--------

secretPhrase = SetSecretWord();
hiddenPhrase = MakeHiddenPhrase(secretPhrase);
numberOfGuessesLeft = 6;

DrawBoard(hiddenPhrase);

do
{
  guess = GetGuess();
  wasAGoodGuess = UpdateBoard(guess, secretPhrase, hiddenPhrase);
  DrawBoard(hiddenPhrase);

  if (!wasAGoodGuess)
    numberOfGuessesLeft--;

}while(!GameIsOver(numberOfGuessesLeft, hiddenPhrase));

DisplayResult(secretPhrase, numberOfGuessesLeft);

Step 3
GetSecretPhrase
---------------

prompt the user for the secret phrase
get the secret phrase

return secret phrase

MakeHiddenPhrase(secretPhrase)
------------------------------

hiddenPhrase = make new cstring given the length of the secret phrase

for (length of the secret phrase)
{
  hiddenPhrase[i] = '-'
}

return hiddenPhrase

UpdateBoard(guess, secretPhrase, hiddenPhrase, numberOfGuessesLeft)
-------------------------------------------------------------------

bool found = false;

for (length of the secretPhrase)
{
  if(secretPhrase[i] == guess)
  {
    hiddenPhrase[i] = guess;
    found = true
  }
}
if(!found)
  numberOfGuessesLeft--

IsGameOver(numberOfGuessesLeft, hiddenPhrase)
---------------------------------------------
bool hasDash = false

for (length of the hiddenPhrase)
{
  if (hiddenPhrase[i] == '-' && !hasDash)
    hasDash = true
}

return numberOfGuessesLeft == 0 || hasDash

*/
```
