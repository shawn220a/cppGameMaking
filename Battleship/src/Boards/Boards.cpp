#include <iostream>

#include "Boards.hpp"
#include "../Players/Players.hpp"
#include "../Ships/Ships.hpp"
#include "../Utils/Utils.hpp"

void SetupBoards(Player& player)
{
  ClearBoards(player);

  for (int i = 0; i < NUM_SHIPS; i++)
  {
    DrawBoards(player);

    Ship& currentShip = player.ships[i];

    ShipPositionType shipPosition;
    ShipOrientationType orientation;

    bool isValidPlacement = false;

    do
    {
      std::cout << player.playerName << " please set the position and orientation for your " << GetShipNameForShipType(currentShip.shipType) << std::endl;

      shipPosition = GetBoardPosition();
      orientation = GetShipOrientation();

      isValidPlacement = IsValidPlacement(player, currentShip, shipPosition, orientation);

      if (!isValidPlacement)
      {
        std::cout << "That was not a valid placement. Please try again." << std::endl;

        WaitForKeyPress();
      }


    } while (!isValidPlacement);

    PlaceShipOnBoard(player, currentShip, shipPosition, orientation);

  }

  DrawBoards(player);

  WaitForKeyPress();
}

void ClearBoards(Player& player)
{
  for (int row = 0; row < BOARD_SIZE; row++)
  {
    for (int col = 0; col < BOARD_SIZE; col++)
    {
      player.guessBoard[row][col] = GT_NONE;
      player.shipBoard[row][col].shipType = ST_NONE;
      player.shipBoard[row][col].isHit = false;
    }
  }
}

void DrawSeparatorLine()
{
  std::cout << " ";

  for (int col = 0; col < BOARD_SIZE; col++)
    std::cout << "+---";

  std::cout << "+";
}

void DrawColumnsRow()
{
  std::cout << "  ";

  for (int col = 0; col < BOARD_SIZE; col++)
  {
    int columnName = col + 1;

    std::cout << " " << columnName << "  ";
  }
}

void DrawShipBoardRow(const Player& player, int row)
{
  char rowName = row + 'A';

  std::cout << rowName << "|";

  for (int col = 0; col < BOARD_SIZE; col++)
  {
    std::cout << " " << GetShipRepresentationAt(player, row, col) << " |";
  }
}

void DrawGuessBoardRow(const Player& player, int row)
{
  char rowName = row + 'A';

  std::cout << rowName << "|";

  for (int col = 0; col < BOARD_SIZE; col++)
  {
    std::cout << " " << GetGuessRepresentationAt(player, row, col) << " |";
  }
}

void DrawBoards(const Player& player)
{
  ClearScreen();

  DrawColumnsRow();

  DrawColumnsRow();

  std::cout << std::endl;

  for (int row = 0; row < BOARD_SIZE; row++)
  {
    DrawSeparatorLine();

    std::cout << " ";

    DrawSeparatorLine();

    std::cout << std::endl;

    DrawShipBoardRow(player, row);

    std::cout << " ";

    DrawGuessBoardRow(player, row);

    std::cout << std::endl;
  }

  DrawSeparatorLine();

  std::cout << " ";

  DrawSeparatorLine();

  std::cout << std::endl;

}

bool IsValidPlacement(const Player& player, const Ship& currentShip, const ShipPositionType& shipPosition, ShipOrientationType orientation)
{
  if (orientation == SO_HORIZONTAL)
    for (int col = shipPosition.col; col < (shipPosition.col + currentShip.shipSize); col++)
    {
      if (player.shipBoard[shipPosition.row][col].shipType != ST_NONE || col >= BOARD_SIZE)
        return false;
    }

  else
    for (int row = shipPosition.row; row < (shipPosition.row + currentShip.shipSize); row++)
    {
      if (player.shipBoard[row][shipPosition.col].shipType != ST_NONE || row >= BOARD_SIZE)
        return false;
    }

  return true;
}

void PlaceShipOnBoard(Player& player, Ship& currentShip, const ShipPositionType& shipPosition, ShipOrientationType orientation)
{
  currentShip.position = shipPosition;
  currentShip.orientation = orientation;

  if (orientation == SO_HORIZONTAL)
    for (int col = shipPosition.col; col < (shipPosition.col + currentShip.shipSize); col++)
    {
      player.shipBoard[shipPosition.row][col].shipType = currentShip.shipType;
      player.shipBoard[shipPosition.row][col].isHit = false;
    }

  else
    for (int row = shipPosition.row; row < (shipPosition.row + currentShip.shipSize); row++)
    {
      player.shipBoard[row][shipPosition.col].shipType = currentShip.shipType;
      player.shipBoard[row][shipPosition.col].isHit = false;
    }
}

ShipType UpdateBoards(ShipPositionType guess, Player& currentPlayer, Player& otherPlayer)
{
  if (otherPlayer.shipBoard[guess.row][guess.col].shipType != ST_NONE)
  {
    currentPlayer.guessBoard[guess.row][guess.col] = GT_HIT;
    otherPlayer.shipBoard[guess.row][guess.col].isHit = true;
  }
  else
  {
    currentPlayer.guessBoard[guess.row][guess.col] = GT_MISSED;
  }

  return otherPlayer.shipBoard[guess.row][guess.col].shipType;

}