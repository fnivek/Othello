#include "GameState.h"

GameState::GameState()
{
}

GameState::GameState(cellmap cells, bool player):
    cells_(cells),
    player_(player)
{

}


void GameState::SetCells(cellmap cells)
{
    cells_ = cells;
}

void GameState::SetPlayer(bool player)
{
    player_ = player;
}
