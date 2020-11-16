#ifndef SHIPS_HPP
#define SHIPS_HPP

#include "../Parts.hpp"

void InitializeShip(Ship& ship, int shipSize, ShipType shipType);
char GetShipRepresentationAt(const Player& player, int row, int col);
const char* GetShipNameForShipType(ShipType shipType);
ShipPositionType GetBoardPosition();
ShipPositionType MapBoardPosition(char rowInput, int colInput);
ShipOrientationType GetShipOrientation();

#endif // SHIPS_HPP