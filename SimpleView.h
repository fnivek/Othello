#ifndef SIMPLEVIEW_H
#define SIMPLEVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QApplication>

#include <iostream>

#include "Cell.h"
#include "Board.h"
#include "GameState.h"
#include "Screen.h"
#include "SimpleStartScreen.h"
#include "SimpleHotseatScreen.h"

class SimpleView : public QWidget
{
    Q_OBJECT
public:
    explicit SimpleView(QWidget *parent = 0);

    void ModelUpdated(GameState gs);

private:
    Board* board_;
    QLabel* game_info_;
    Screen* current_screen_ = nullptr;

    // Functions

    /*
     * Close any screen
     */
    void CloseScreen();
    
signals:
    void BoardClicked(cellpos);
    void HotseatClicked();
    
public slots:
    
};

#endif // SIMPLEVIEW_H
