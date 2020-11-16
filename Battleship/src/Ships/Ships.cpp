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