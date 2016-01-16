#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Cell.h"

using namespace std;

class GameState
{
public:
    static const bool WHITE_PLAYER = true;
    static const bool BLACK_PLAYER = false;

    enum screen_type {
        START,
        SINGLE,
        HOTSEAT,
        ONLINE,
        GAME_OVER
    };

public:
    GameState();
    GameState(cellmap pieces, cellposset playablecells, bool player, screen_type current_screen);

    void SetCells(cellmap pieces);
    void SetPlayer(bool player);

    bool isGameOver();

    cellmap pieces_;
    cellposset playablecells_;
    bool player_ = WHITE_PLAYER;
    screen_type current_screen_;

};

#endif // GAMESTATE_H
