#include <iostream>
#include <cstring>

#include "Utils/Utils.hpp"
#include "Boards/Boards.hpp"
#include "Players/Players.hpp"
#include "Ships/Ships.hpp"

void PlayGame(Player& player1, Player& player2);
bool WantToPlayAgain();
bool isGameOver(const Player& player1, const Player& player2);
bool AreAllShipsSunk(const Player& player);
bool IsSunk(const Player& player, const Ship& ship);
void SwitchPlayers(Player** currentPlayer, Player** otherPlayer);
void DisplayWinner(const Player& player1, const Player& player2);

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

void PlayGame(Player& player1, Player& player2)
{
  SetupBoards(player1);
  SetupBoards(player2);

  Player* currentPlayer = &player1;
  Player* otherPlayer = &player2;

  ShipPositionType guess;

  do
  {
    DrawBoards(*currentPlayer);

    bool isValidGuess;

    do
    {
      std::cout << currentPlayer->playerName << " what is your guess? " << std::endl;

      guess = GetBoardPosition();

      isValidGuess = currentPlayer->guessBoard[guess.row][guess.col] == GT_NONE;

      if (!isValidGuess)
        std::cout << "That was not a valid guess! Please try again." << std::endl;

    } while (!isValidGuess);

    ShipType type = UpdateBoards(guess, *currentPlayer, *otherPlayer);

    DrawBoards(*currentPlayer);

    if (type != ST_NONE && IsSunk(*otherPlayer, otherPlayer->ships[type - 1]))
      std::cout << "You sunk " << otherPlayer->playerName << "'s " << GetShipNameForShipType(type) << "!" << std::endl;

    WaitForKeyPress();

    SwitchPlayers(&currentPlayer, &otherPlayer);

  } while (!isGameOver(player1, player2));

  DisplayWinner(player1, player2);
}

bool WantToPlayAgain()
{
  const char* INPUT_ERROR_STRING = "Input error! Please try again.";

  char input;

  const char validInput[2] = { 'y', 'n' };

  input = GetCharacter("Would you like to play again? (y/n): ", INPUT_ERROR_STRING, validInput, 2, CC_LOWER_CASE);

  return input == 'y';
}

bool isGameOver(const Player& player1, const Player& player2)
{
  return AreAllShipsSunk(player1) || AreAllShipsSunk(player2);
}

bool AreAllShipsSunk(const Player& player)
{
  for (int i = 0; i < NUM_SHIPS; i++)
  {
    if (!IsSunk(player, player.ships[i]))
      return false;
  }

  return true;
}

bool IsSunk(const Player& player, const Ship& ship)
{
  if (ship.orientation == SO_HORIZONTAL)
  {
    for (int col = ship.position.col; col < (ship.position.col + ship.shipSize); col++)
    {
      if (!player.shipBoard[ship.position.row][col].isHit)
        return false;
    }
  }
  else
  {
    for (int row = ship.position.row; row < (ship.position.row + ship.shipSize); row++)
    {
      if (!player.shipBoard[row][ship.position.col].isHit)
        return false;
    }
  }

  return true;
}

void SwitchPlayers(Player** currentPlayer, Player** otherPlayer)
{
  Player* temp = *currentPlayer;
  *currentPlayer = *otherPlayer;
  *otherPlayer = temp;
}

void DisplayWinner(const Player& player1, const Player& player2)
{
  if (AreAllShipsSunk(player1))
    std::cout << "Congratulations " << player2.playerName << "! You won!" << std::endl;
  else
    std::cout << "Congratulations " << player1.playerName << "! You won!" << std::endl;
}