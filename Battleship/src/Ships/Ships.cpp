#include <iostream>

#include "Ships.hpp"

void InitializeShip(Ship& ship, int shipSize, ShipType shipType)
{
  ship.shipType = shipType;
  ship.shipSize = shipSize;
  ship.position.row = 0;
  ship.position.col = 0;
  ship.orientation = SO_HORIZONTAL;
}