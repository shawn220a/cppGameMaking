#ifndef SHIPS_HPP
#define SHIPS_HPP

#include "../Parts.hpp"

void InitializeShip(Ship& ship, int shipSize, ShipType shipType);
char GetShipRepresentationAt(const Player& player, int row, int col);

#endif // SHIPS_HPP