#ifndef BASESCREEN_H
#define BASESCREEN_H

#include <QWidget>

#include "GameState.h"

class BaseScreen : public QWidget
{
    Q_OBJECT
public:
    // The derived constructor must instantiate the visuals of the screen and
    //  make the appropriate signals connect to the controller's (Othello class)
    //  coresponding slots
    explicit BaseScreen(QWidget *parent = 0);

    // This function takes a gamestate pointer and uses the current gamestate
    //  to update its visuals
    virtual void Update(GameState* gs) = 0;
    
signals:
    
public slots:
    
};

#endif // BASESCREEN_H
