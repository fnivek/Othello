#ifndef OTHELLO_H
#define OTHELLO_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>

#include <set>
#include <iostream>

#include "Board.h"
#include "Cell.h"
#include "GameState.h"

using namespace std;

class Othello : public QWidget
{
    Q_OBJECT
    
public:
    Othello(QWidget *parent = 0);
    ~Othello();

private:
    unsigned short board_size_ = 8;
    Board* board_;

    cellmap cells_;

    void InitilizeCells();

    void UpdateBoard();

    bool player_ = GameState::WHITE_PLAYER;


};

#endif // OTHELLO_H
