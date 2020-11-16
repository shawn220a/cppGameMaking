#include <iostream>
#include <cctype>

#include "Utils.hpp"

const int IGNORE_CHARS = 256;

char GetCharacter(const char* prompt, const char* error)
{
  char input;
  bool failure;

  do
  {
    failure = false;

    std::cout << prompt;
    std::cin >> input;

    if (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(IGNORE_CHARS, '\n');
      std::cout << error << std::endl;
      failure = true;
    }
    else
    {
      std::cin.ignore(IGNORE_CHARS, '\n');

      if (isalpha(input))
        input = tolower(input);
      else
      {
        std::cout << error << std::endl;

        failure = true;
      }
    }

  } while (failure);

  return input;
}

char GetCharacter(const char* prompt, const char* error, const char validInput[], int validInputLength, CharacterCaseType charCase)
{
  char input;
  bool failure;

  do
  {
    failure = false;

    std::cout << prompt;
    std::cin >> input;

    if (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(IGNORE_CHARS, '\n');
      std::cout << error << std::endl;
      failure = true;
    }
    else
    {
      std::cin.ignore(IGNORE_CHARS, '\n');

      if (isalpha(input))
      {
        if (charCase == CC_UPPER_CASE)
        {
          input = toupper(input);
        }
        else if (charCase == CC_LOWER_CASE)
        {
          input = tolower(input);
        }

        for (int i = 0; i < validInputLength; i++)
        {
          if (input == validInput[i])
            return input;
        }
      }
      std::cout << error << std::endl;

      failure = true;
    }
  } while (failure);

  return input;
}

int GetInteger(const char* prompt, const char* error, const int validInput[], int validInputLength)
{
  int input;
  bool inputFailure;

  const int IGNORE_CHARS = 256;
  do
  {

    inputFailure = false;

    std::cout << prompt;
    std::cin >> input;

    if (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(IGNORE_CHARS, '\n');
      std::cout << error << std::endl;
      inputFailure = true;
    }
    else
    {
      for (int i = 0;i < validInputLength; i++)
      {
        if (input == validInput[i])
        {
          return input;
        }
      }


      std::cout << error << std::endl;
      inputFailure = true;
    }


  } while (inputFailure);

  return -1;

}

void ClearScreen()
{
  // system("cls"); // Windows only
  system("clear"); // MacOS only
}

void WaitForKeyPress()
{
  // system("pause"); // Windows only
  system("read -n 1 -s -p \"Press any key to continue...\";echo"); // MacOs only
}
