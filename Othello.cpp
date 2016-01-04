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

    // Connect signals and slots
    connect(board_, SIGNAL(BoardClicked(cellpos)), this, SLOT(BoardClicked(cellpos)));
}

Othello::~Othello()
{
    
}

void Othello::InitilizeCells()
{
    // Set center four pieces
    unsigned short p = (board_size_ / 2) - 1;
    pieces_.insert({{p,      p},     Cell{Cell::WHITE}});
    pieces_.insert({{p+1,    p},     Cell{Cell::BLACK}});
    pieces_.insert({{p,      p+1},   Cell{Cell::BLACK}});
    pieces_.insert({{p+1,    p+1},   Cell{Cell::WHITE}});
}

void Othello::UpdateBoard()
{
    board_->ModelUpdated(GameState(pieces_, GetPlayableCells(), player_));
}

void Othello::BoardClicked(cellpos pos)
{
    pieces_.insert({{pos.first, pos.second}, Cell{player_}});

    player_ = !player_;

    UpdateBoard();
}

cellposset Othello::GetPlayableCells()
{
    auto cells = cellposset();
    cells.insert({1,1});
    return cells;
}
