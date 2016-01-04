#include "Othello.h"

Othello::Othello(QWidget *parent)
    : QWidget(parent),
      board_(new Board)
{
    // Place Widgets in a layout
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(board_);
    setLayout(layout);

    // Set up game
    InitilizeCells();

    // Send state to board
    UpdateBoard();
}

Othello::~Othello()
{
    
}

void Othello::InitilizeCells()
{
    // Set center four pieces
    unsigned short p = (board_size_ / 2) - 1;
    cells_.insert({{p,      p},     Cell{Cell::WHITE}});
    cells_.insert({{p+1,    p},     Cell{Cell::BLACK}});
    cells_.insert({{p,      p+1},   Cell{Cell::BLACK}});
    cells_.insert({{p+1,    p+1},   Cell{Cell::WHITE}});
}

void Othello::UpdateBoard()
{
    board_->ModelUpdated(GameState(cells_, player_));
}

