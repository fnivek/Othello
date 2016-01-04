#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <map>

#include "Cell.h"

using namespace std;

class GameState
{
public:
    static const bool WHITE_PLAYER = true;
    static const bool BLACK_PLAYER = false;

public:
    GameState();
    GameState(cellmap cells, bool player);

    void SetCells(cellmap cells);
    void SetPlayer(bool player);

    cellmap cells_;
    bool player_ = WHITE_PLAYER;
};

#endif // GAMESTATE_H
