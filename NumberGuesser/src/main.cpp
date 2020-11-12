#include <iostream>
#include <cmath>
#include <cctype>
#include <stdlib.h>
#include <ctime>

void PlayGame();
bool WantToPlayAgain();
bool IsGameOver(int secretNumber, int numberOfTries, int guess);
int GetGuess(int numberOfTries);
void DisplayResult(int secretNumber, int numberOfTries);

const int IGNORE_CHARS = 256;

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

    srand((unsigned int)time(NULL));

    do
    {
        PlayGame();
    } while (WantToPlayAgain());

    return 0;
}

void PlayGame()
{
    const int UPPER_BOUND = 100;

    int secretNumber = rand() % UPPER_BOUND;
    int numberOfTries = ceil(log2(UPPER_BOUND));
    int guess = 0;

    std::cout << "The range of the number is between 0 and 100" << std::endl;

    do
    {
        guess = GetGuess(numberOfTries);

        if (guess != secretNumber)
        {
            numberOfTries--;

            if (guess > secretNumber)
                std::cout << "Your guess was too high!" << std::endl;
            else
                std::cout << "Your guess was too low!" << std::endl;
        }
    } while (!IsGameOver(secretNumber, numberOfTries, guess));

    DisplayResult(secretNumber, numberOfTries);
}

bool WantToPlayAgain()
{
    char input;
    bool failure;

    do
    {
        failure = false;

        std::cout << "Would you like to play again? (y/n) ";
        std::cin >> input;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(IGNORE_CHARS, '\n');
            std::cout << "Input error! Please try again." << std::endl;
            failure = true;
        }
        else
        {
            std::cin.ignore(IGNORE_CHARS, '\n');

            input = tolower(input);
        }

    } while (failure);

    return input == 'y';
}

bool IsGameOver(int secretNumber, int numberOfTries, int guess)
{
    return secretNumber == guess || numberOfTries <= 0;
}

int GetGuess(int numberOfTries)
{
    int guess;
    bool failure;

    do
    {
        failure = false;

        std::cout << "Please enter your gues (number of guesses left: " << numberOfTries << "): ";
        std::cin >> guess;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(IGNORE_CHARS, '\n');
            std::cout << "Input error! Please try again." << std::endl;
            failure = true;
        }

    } while (failure);

    return guess;
}

void DisplayResult(int secretNumber, int numberOfTries)
{
    if (numberOfTries > 0)
        std::cout << "You got it! It was: " << secretNumber << std::endl;
    else
        std::cout << "You didn't get it.... It was: " << secretNumber << std::endl;
}