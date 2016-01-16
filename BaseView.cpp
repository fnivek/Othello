#include "BaseView.h"

BaseView::BaseView(QWidget *parent) :
    QWidget(parent),
    layout_(new QVBoxLayout),
    current_screen_(new SimpleStartScreen(this))
{
    layout_->setContentsMargins(0,0,0,0);
    layout_->addWidget(current_screen_);
    setLayout(layout_);
}

void BaseView::ModelUpdated(GameState gs)
{
    current_screen_->Update(&gs);
}
