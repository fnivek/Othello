#include "SimpleHotseatScreen.h"

SimpleHotseatScreen::SimpleHotseatScreen(QWidget *view, Board* board):
    Screen(view),
    board_(board),
    game_info_(new QLabel)
{
}

QLayout* SimpleHotseatScreen::GetLayout()
{
    if(layout_)
    {
        return layout_;
    }

    QVBoxLayout* temp = new QVBoxLayout;

    temp->addWidget(game_info_);
    temp->addWidget(board_, 1);

    layout_ = temp;

    // Connections
    QObject::connect(board_, SIGNAL(BoardClicked(cellpos)), view_, SIGNAL(BoardClicked(cellpos)));

    return layout_;
}

GameState::screen_type SimpleHotseatScreen::GetType()
{
    return GameState::HOTSEAT;
}

bool SimpleHotseatScreen::Update(GameState& gs)
{
    board_->ModelUpdated(gs);

    if(gs.player_ == GameState::WHITE_PLAYER)
        game_info_->setText("White players turn");
    else
        game_info_->setText("Black players turn");

    // Check if gameover
    if(gs.isGameOver())
    {
        game_info_->setText("Game Over");
    }

    return true;
}
