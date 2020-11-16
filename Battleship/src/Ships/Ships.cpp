#include <iostream>

#include "Ships.hpp"
#include "../Utils/Utils.hpp"

void InitializeShip(Ship& ship, int shipSize, ShipType shipType)
{
  ship.shipType = shipType;
  ship.shipSize = shipSize;
  ship.position.row = 0;
  ship.position.col = 0;
  ship.orientation = SO_HORIZONTAL;
}

char GetShipRepresentationAt(const Player& player, int row, int col)
{
  if (player.shipBoard[row][col].isHit)
    return '*'; // represents hit

  if (player.shipBoard[row][col].shipType == ST_AIRCRAFT_CARRIER)
    return 'A'; // represents aircraft carrier

  else if (player.shipBoard[row][col].shipType == ST_BATTLESHIP)
    return 'B'; // represents battleship

  else if (player.shipBoard[row][col].shipType == ST_CRUISER)
    return 'C'; // represents cruiser

  else if (player.shipBoard[row][col].shipType == ST_DESTROYER)
    return 'D'; // represents destroyer

  else if (player.shipBoard[row][col].shipType == ST_SUBMARINE)
    return 'S'; // represents submarine

  else
    return ' ';
}

const char* GetShipNameForShipType(ShipType shipType)
{
  if (shipType == ST_AIRCRAFT_CARRIER)
    return "Aircraft Carrier";

  else if (shipType == ST_BATTLESHIP)
    return "Battleship";

  else if (shipType == ST_CRUISER)
    return "Cruiser";

  else if (shipType == ST_DESTROYER)
    return "Destroyer";

  else if (shipType == ST_SUBMARINE)
    return "Submarine";

  return "None";
}

ShipPositionType GetBoardPosition()
{
  const char* INPUT_ERROR_STRING = "Input error! Please try again.";

  char rowInput;
  int colInput;

  const char validRowsInput[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
  const int validColumnsInput[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  rowInput = GetCharacter("Please input a row (A-J): ", INPUT_ERROR_STRING, validRowsInput, BOARD_SIZE, CC_UPPER_CASE);
  colInput = GetInteger("Please input a column (1-10): ", INPUT_ERROR_STRING, validColumnsInput, BOARD_SIZE);

  return MapBoardPosition(rowInput, colInput);
}

ShipPositionType MapBoardPosition(char rowInput, int colInput)
{
  int realRow = rowInput - 'A';
  int realCol = colInput - 1;

  ShipPositionType boardPosition;

  boardPosition.row = realRow;
  boardPosition.col = realCol;

  return boardPosition;
}

ShipOrientationType GetShipOrientation()
{
  const char* INPUT_ERROR_STRING = "Input error! Please try again.";

  const char validInput[2] = { 'H', 'V' };

  char input = GetCharacter("Plese choose an orientation (H) for Horizontal or (V) for Vertical: ", INPUT_ERROR_STRING, validInput, 2, CC_UPPER_CASE);

  if (input == validInput[0])
    return SO_HORIZONTAL;
  else
    return SO_VERTICAL;
}

ShipPositionType GetRandomPosition()
{
  ShipPositionType guess;

  guess.row = rand() % BOARD_SIZE;
  guess.col = rand() % BOARD_SIZE;

  return guess;
}