#include <iostream>

#include "Players.hpp"

void InitializePlayer(Player& player, const char* playerName)
{
  if (playerName != nullptr && strlen(playerName) > 0)
    strcpy(player.playerName, playerName);

  InitializeShip(player.ships[0], AIRCRAFT_CARRIER_SIZE, ST_AIRCRAFT_CARRIER);
  InitializeShip(player.ships[1], BATTLESHIP_SIZE, ST_BATTLESHIP);
  InitializeShip(player.ships[2], CRUISER_SIZE, ST_CRUISER);
  InitializeShip(player.ships[3], DESTROYER_SIZE, ST_DESTROYER);
  InitializeShip(player.ships[4], SUBMARINE_SIZE, ST_SUBMARINE);
}