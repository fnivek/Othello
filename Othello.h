#ifndef OTHELLO_H
#define OTHELLO_H

#include <QMainWindow>

class Othello : public QMainWindow
{
    Q_OBJECT
    
public:
    Othello(QWidget *parent = 0);
    ~Othello();
};

#endif // OTHELLO_H
