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
}

Othello::~Othello()
{
    
}

void Othello::InitilizeCells()
{
    // Initilize all cells to empty
    cells_ = vector<vector<Cell::cell_type>>(board_size_);
    for(auto&& row : cells_)
    {
        row = vector<Cell::cell_type>(board_size_);
        for(auto cell : row)
        {
            cell = Cell::EMPTY;
        }
    }

    // Set center four pieces
    unsigned short p = (board_size_ / 2) - 1;
    cells_[p][p] =      Cell::WHITE;
    cells_[p+1][p] =    Cell::BLACK;
    cells_[p][p+1] =    Cell::BLACK;
    cells_[p+1][p+1] =  Cell::WHITE;

}

