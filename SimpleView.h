#ifndef SIMPLEVIEW_H
#define SIMPLEVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

#include "Cell.h"
#include "Board.h"
#include "GameState.h"

class SimpleView : public QWidget
{
    Q_OBJECT
public:
    explicit SimpleView(QWidget *parent = 0);

    void ModelUpdated(GameState gs);

private:
    Board* board_;
    GameState gs_;
    QLabel* game_info_;
    
signals:
    void BoardClicked(cellpos);
    
public slots:
    
};

#endif // SIMPLEVIEW_H
