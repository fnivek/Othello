#include "GameState.h"

GameState::GameState()
{
}

GameState::GameState(vector<Cell> &pieces, bool player):
    pieces_(pieces),
    player_(player)
{

}


void GameState::SetPieces(vector<Cell>& pieces)
{
    pieces_ = pieces;
}

void GameState::SetPlayer(bool player)
{
    player_ = player;
}
