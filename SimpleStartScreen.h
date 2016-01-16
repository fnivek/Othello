#ifndef SIMPLESTARTSCREEN_H
#define SIMPLESTARTSCREEN_H

#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "BaseScreen.h"

class SimpleStartScreen : public BaseScreen
{
public:
    SimpleStartScreen(QWidget* parent);
    void Update(GameState *gs);

private:
    QPushButton* single = new QPushButton("Play the Computer");
    QPushButton* hotseat = new QPushButton("Play Hotseat");
    QPushButton* online = new QPushButton("Play Online");
    QPushButton* quit = new QPushButton("Quit");
};

#endif // SIMPLESTARTSCREEN_H
