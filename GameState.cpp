#include "GameState.h"

GameState::GameState()
{
}

GameState::GameState(cellmap pieces, cellposset playablecells, bool player, screen_type current_screen):
    pieces_(pieces),
    playablecells_(playablecells),
    player_(player),
    current_screen_(current_screen)
{}


void GameState::SetCells(cellmap pieces)
{
    pieces_ = pieces;
}

void GameState::SetPlayer(bool player)
{
    player_ = player;
}

bool GameState::isGameOver()
{
    return !(playablecells_.size());
}
