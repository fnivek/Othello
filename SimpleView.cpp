#include "SimpleView.h"

SimpleView::SimpleView(QWidget *parent) :
    QWidget(parent),
    board_(new Board),
    game_info_(new QLabel)
{
    // Place Widgets in a layout
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(game_info_);
    layout->addWidget(board_, 1);
    setLayout(layout);

    connect(board_, SIGNAL(BoardClicked(cellpos)), this, SIGNAL(BoardClicked(cellpos)));
}

void SimpleView::ModelUpdated(GameState gs)
{
    gs_ = gs;
    board_->ModelUpdated(gs_);

    if(gs_.player_ == GameState::WHITE_PLAYER)
        game_info_->setText("White players turn");
    else
        game_info_->setText("Black players turn");
    update();
}
