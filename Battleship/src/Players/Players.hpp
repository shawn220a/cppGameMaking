#ifndef PLAYERS_HPP
#define PLAYERS_HPP

#include "../Parts.hpp"

void InitializePlayer(Player& player, const char* playerName);
char GetGuessRepresentationAt(const Player& player, int row, int col);
PlayerType GetPlayer2Type();

#endif // PLAYERS_HPP