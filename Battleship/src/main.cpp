#include <iostream>
#include <cstring>

#include "Utils/Utils.hpp"
#include "Boards/Boards.hpp"
#include "Players/Players.hpp"

using namespace std;

const char* INPUT_ERROR_STRING = "Input error! Please try again.";

void InitializeShip(Ship& ship, int shipSize, ShipType shipType);
void PlayGame(Player& player1, Player& player2);
bool WantToPlayAgain();

int main()
{
  Player player1;
  Player player2;

  InitializePlayer(player1, "Player1");
  InitializePlayer(player2, "Player2");

  do
  {
    PlayGame(player1, player2);
  } while (WantToPlayAgain());

  return 0;
}

void InitializeShip(Ship& ship, int shipSize, ShipType shipType)
{
  ship.shipType = shipType;
  ship.shipSize = shipSize;
  ship.position.row = 0;
  ship.position.col = 0;
  ship.orientation = SO_HORIZONTAL;
}

void PlayGame(Player& player1, Player& player2)
{
  SetupBoards(player1);
  SetupBoards(player2);
}

bool WantToPlayAgain()
{
  char input;

  const char validInput[2] = { 'y', 'n' };

  input = GetCharacter("Would you like to play again? (y/n): ", INPUT_ERROR_STRING, validInput, 2, CC_LOWER_CASE);

  return input == 'y';
}
