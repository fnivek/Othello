#include "GameState.h"

GameState::GameState()
{
}

GameState::GameState(cellmap pieces, cellposset playablecells, bool player):
    pieces_(pieces),
    playablecells_(playablecells),
    player_(player)
{}


void GameState::SetCells(cellmap pieces)
{
    pieces_ = pieces;
}

void GameState::SetPlayer(bool player)
{
    player_ = player;
}
