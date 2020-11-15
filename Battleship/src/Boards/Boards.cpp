#include <iostream>

#include "Boards.hpp"
#include "../Players/Players.hpp"

void SetupBoards(Player& player)
{
  ClearBoards(player);

  DrawBoards(player);
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
    std::cout << " " << " " << " |";
  }
}

void DrawGuessBoardRow(const Player& player, int row)
{
  char rowName = row + 'A';

  std::cout << rowName << "|";

  for (int col = 0; col < BOARD_SIZE; col++)
  {
    std::cout << " " << " " << " |";
  }
}

void DrawBoards(const Player& player)
{
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