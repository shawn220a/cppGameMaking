#include <iostream>
#include <cstring>

#include "Utils.hpp"

using namespace std;

const char* INPUT_ERROR_STRING = "Input error! Please try again.";

enum
{
  AIRCRAFT_CARRIER_SIZE = 5,
  BATTLESHIP_SIZE = 4,
  CRUISER_SIZE = 3,
  DESTROYER_SIZE = 3,
  SUBMARINE_SIZE = 2,

  BOARD_SIZE = 10,
  NUM_SHIPS = 5,
  PLAYER_NAME_SIZE = 8, // Player1, Player2
  MAX_SIP_SIZE = AIRCRAFT_CARRIER_SIZE,
};

enum ShipType
{
  ST_NONE = 0,
  ST_AIRCRAFT_CARRIER,
  ST_BATTLESHIP,
  ST_CRUISER,
  ST_DESTROYER,
  ST_SUBMARINE
};

enum ShipOrientationType
{
  SO_HORIZONTAL = 0,
  SO_VERTICAL
};

struct ShipPositionType
{
  int row;
  int col;
};

struct Ship
{
  ShipType shipType;
  int shipSize;
  ShipOrientationType orientation;
  ShipPositionType position;
};

enum GuessType
{
  GT_NONE = 0,
  GT_MISSED,
  GT_HIT
};

struct ShipPartType
{
  ShipType shipType;
  bool isHit;
};

struct Player
{
  char playerName[PLAYER_NAME_SIZE];
  Ship ships[NUM_SHIPS];
  GuessType guessBoard[BOARD_SIZE][BOARD_SIZE];
  ShipPartType shipBoard[BOARD_SIZE][BOARD_SIZE];
};

void InitializePlayer(Player& player, const char* playerName);
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

void InitializePlayer(Player& player, const char* playerName)
{
  if (playerName != nullptr && strlen(playerName) > 0)
  {
    strcpy(player.playerName, playerName);
  }

  InitializeShip(player.ships[0], AIRCRAFT_CARRIER_SIZE, ST_AIRCRAFT_CARRIER);
  InitializeShip(player.ships[1], BATTLESHIP_SIZE, ST_BATTLESHIP);
  InitializeShip(player.ships[2], CRUISER_SIZE, ST_CRUISER);
  InitializeShip(player.ships[3], DESTROYER_SIZE, ST_DESTROYER);
  InitializeShip(player.ships[4], SUBMARINE_SIZE, ST_SUBMARINE);

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

}

bool WantToPlayAgain()
{
  char input;

  const char validInput[2] = { 'y', 'n' };

  input = GetCharacter("Would you like to play again? (y/n): ", INPUT_ERROR_STRING, validInput, 2, CC_LOWER_CASE);

  return input == 'y';
}