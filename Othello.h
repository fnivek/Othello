#ifndef OTHELLO_H
#define OTHELLO_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>

#include <set>
#include <array>

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

    cellmap pieces_;

    cellposset playable_cells_;

    bool player_ = GameState::BLACK_PLAYER;

    static const array<celldir, 4> CARDINAL_DIRS;

    static const array<celldir, 8> ALL_DIRS;

    void InitilizeCells();

    void UpdateBoard();

    cellposset GetPlayableCells(bool player);

    void PlacePiece(cellpos pos);

    bool isValidDir(cellpos pos, celldir dir, bool player);

    bool isCellposOnBoard(cellpos pos);


public slots:
    void BoardClicked(cellpos pos);


};

#endif // OTHELLO_H
