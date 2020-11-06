#include <iostream>

using namespace std;

int main()
{
    // We need a variable that stores the secret number
    // range: 0-100
    // We need a variable that stores the number of guesses the player has left
    // We need a variable that will store the player's guess
    // Number of guesses will be the log base 2 of the upper range - e.g. log2(100) ~ 6.64 -> 7
    // How do we change the secret number?

    /*
        do
        {
            Play The Game

        } while (Want to play again)

        Play the Game:

        1. Set the secret number - set it to a known value for now
        2. Set the number of guesses -> ceil(log2(100))

        do
        {
            3. Prompt the user to make a guess (output the number of guesses left)
            4. Get the guess from the player
            5. Check to see if the guess is equal to the secret number
                5a. If the guess is not equal to secret number then
                    5a1. Decrement the number of guesses left
                    5a2. Check to see if the guess was higher or lower than the secret number
                        5a2a. If it was higher - print that the guess was too high
                        5a2b. If the guess was lower - then print that the guess was too low
            
        } while (the game is not over)

        Display the result - tell the player if he got it or not

        Functions:

        Play the Game -> PlayGame()
        Want to play again -> WantToPlayAgain()
        Get the guess from the player -> GetGuess()

        The game is not over -> IsGameOver()
        - Number of guesses left == 0 || player's guess == secret number

        Display result -> DisplayResult()
        if (the player go it)
        {
            print that they go t it and print the secret number
        }
        else
        {
            print that they didn't get it and print the secret number
        }

    */

    return 0;
}