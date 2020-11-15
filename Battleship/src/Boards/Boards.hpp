#ifndef BOARDS_HPP
#define BOARDS_HPP

void SetupBoards(Player& player);
void ClearBoards(Player& player);
void DrawBoards(const Player& player);
void DrawSeparatorLine();
void DrawColumnsRow();
void DrawShipBoardRow(const Player& player, int row);

#endif // BOARDS_HPP