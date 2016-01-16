#ifndef SCREEN_H
#define SCREEN_H

#include <QLayout>
#include <QWidget>

#include "GameState.h"

class Screen
{
public:
    virtual QLayout* GetLayout() = 0;
    virtual GameState::screen_type GetType() = 0;
    virtual bool Update(GameState& gs) = 0;
    virtual ~Screen() {delete layout_;}

protected:
    Screen(QWidget* view){view_ = view;}
    QLayout* layout_ = nullptr;
    QWidget* view_ = nullptr;

};

#endif // SCREEN_H
