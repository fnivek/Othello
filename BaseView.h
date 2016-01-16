#ifndef BASEVIEW_H
#define BASEVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLayout>

#include "Cell.h"
#include "GameState.h"
#include "BaseScreen.h"
#include "SimpleStartScreen.h"

class BaseView : public QWidget
{
    Q_OBJECT
public:
    explicit BaseView(QWidget *parent = 0);

    void ModelUpdated(GameState gs);

protected:
    GameState gs_;
    BaseScreen* current_screen_;
    QLayout* layout_;
    
signals:
    void BoardClicked(cellpos);
    
public slots:
    
};

#endif // BASEVIEW_H
