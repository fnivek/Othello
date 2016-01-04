#ifndef OTHELLO_H
#define OTHELLO_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>

#include <set>

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

    bool player_ = GameState::BLACK_PLAYER;

    void InitilizeCells();

    void UpdateBoard();

    cellposset GetPlayableCells();




public slots:
    void BoardClicked(cellpos pos);


};

#endif // OTHELLO_H
