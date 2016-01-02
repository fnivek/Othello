#ifndef OTHELLO_H
#define OTHELLO_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include "Board.h"

class Othello : public QWidget
{
    Q_OBJECT
    
public:
    Othello(QWidget *parent = 0);
    ~Othello();

private:
    Board* board_;
    QLabel* test_;

};

#endif // OTHELLO_H
