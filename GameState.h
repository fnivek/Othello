#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Cell.h"

using namespace std;

class GameState
{
public:
    static const bool WHITE_PLAYER = true;
    static const bool BLACK_PLAYER = false;

public:
    GameState();
    GameState(cellmap pieces, cellposset playablecells, bool player);

    void SetCells(cellmap pieces);
    void SetPlayer(bool player);

    cellmap pieces_;
    cellposset playablecells_;
    bool player_ = WHITE_PLAYER;
};

#endif // GAMESTATE_H
