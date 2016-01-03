#ifndef OTHELLO_H
#define OTHELLO_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>

#include <vector>
#include <iostream>

#include "Board.h"
#include "Cell.h"

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

    vector<vector<Cell::cell_type>> cells_;

    void InitilizeCells();


};

#endif // OTHELLO_H
