#ifndef SIMPLEHOTSEATSCREEN_H
#define SIMPLEHOTSEATSCREEN_H

#include <QLabel>
#include <QVBoxLayout>
#include <QObject>
#include <QApplication>

#include "Screen.h"
#include "Board.h"
#include "Cell.h"

class SimpleHotseatScreen : public Screen
{
public:
    SimpleHotseatScreen(QWidget *view, Board* board);
    virtual QLayout* GetLayout();
    virtual GameState::screen_type GetType();
    virtual bool Update(GameState& gs);

protected:
    Board* board_;
    QLabel* game_info_;
};

#endif // SIMPLEHOTSEATSCREEN_H
