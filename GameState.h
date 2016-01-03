#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>

#include "Cell.h"

using namespace std;

class GameState
{
public:
    static const bool WHITE_PLAYER = true;
    static const bool BLACK_PLAYER = false;

public:
    GameState();
    GameState(vector<Cell>& pieces, bool player);

    void SetPieces(vector<Cell>& pieces);
    void SetPlayer(bool player);

    vector<Cell> pieces_;
    bool player_ = WHITE_PLAYER;
};

#endif // GAMESTATE_H
