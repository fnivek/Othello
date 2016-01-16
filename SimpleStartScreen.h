#ifndef SIMPLESTARTSCREEN_H
#define SIMPLESTARTSCREEN_H


#include <QPushButton>
#include <QObject>
#include <QApplication>

#include "Screen.h"

class SimpleStartScreen : public Screen
{
public:
    SimpleStartScreen(QWidget* view);
    virtual QLayout* GetLayout();
    virtual GameState::screen_type GetType();
    virtual bool Update(GameState& gs);
};

#endif // SIMPLESTARTSCREEN_H
