#ifndef BOARDS_HPP
#define BOARDS_HPP

#include "../Parts.hpp"

void SetupBoards(Player& player);
void ClearBoards(Player& player);
void DrawBoards(const Player& player);
void DrawSeparatorLine();
void DrawColumnsRow();
void DrawShipBoardRow(const Player& player, int row);
bool IsValidPlacement(const Player& player, const Ship& currentShip, const ShipPositionType& shipPosition, ShipOrientationType orientation);
void PlaceShipOnBoard(Player& player, Ship& currentShip, const ShipPositionType& shipPosition, ShipOrientationType orientation);
ShipType UpdateBoards(ShipPositionType guess, Player& currentPlayer, Player& otherPlayer);

#endif // BOARDS_HPP