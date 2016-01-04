#include "Othello.h"

const array<celldir, 4> Othello::CARDINAL_DIRS{{
        {{-1, 0}}, {{ 0,-1}},
        {{ 1, 0}}, {{ 0, 1}}
                                                         }};

const array<celldir, 8> Othello::ALL_DIRS{{
        {{1, 0}}, {{1, 1}}, {{0, 1}}, {{-1, 1}},
        {{-1, 0}}, {{-1, -1}}, {{0, -1}}, {{1, -1}}
                                                }};

Othello::Othello(QWidget *parent)
    : QWidget(parent),
      board_(new Board)
{
    // Place Widgets in a layout
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(board_);
    setLayout(layout);

    // Set up game
    player_ = GameState::BLACK_PLAYER;
    InitilizeCells();
    playable_cells_ = GetPlayableCells(player_);

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
    board_->ModelUpdated(GameState(pieces_, playable_cells_, player_));
}

void Othello::BoardClicked(cellpos pos)
{
    if(playable_cells_.count(pos))
    {
        PlacePiece(pos);
    }
}

cellposset Othello::GetPlayableCells(bool player)
{
    cellposset cells = cellposset();
    // Itterate through all pieces_
    for(auto&& p : pieces_)
    {
        auto&& piece = p.second;
        auto pos = p.first;

        // If all four adjacent sides are full move on
        if(piece.surrounded_)
        {
            continue;
        }

        // Check if piece is player color
        if(piece.type_ == player)
        {
            continue;
        }

        // Check all neibours
        bool surrounded = true;
        for(auto dir : CARDINAL_DIRS)
        {
            cellpos new_pos = pos + dir;

            // Check if new pos is on board
            if(!isCellposOnBoard(new_pos))
            {
                continue;
            }

            // if new pos is ocupied move on
            if(pieces_.count(new_pos))
            {
                continue;
            }

            // This direction is empty
            // Check to see if any dirs are valid
            surrounded = false;
            for(auto dir2 : Othello::ALL_DIRS)
            {
                if(isValidDir(new_pos, dir2, player))
                {
                    cells.insert(new_pos);
                    break;
                }
            }

        }

        piece.surrounded_ = surrounded;

    }
    return cells;
}

// This function does not check if the position is valid
void Othello::PlacePiece(cellpos pos)
{
    // Place the piece
    pieces_.insert({pos, Cell(player_)});

    // Flip pieces
    FlipPieces(pos, player_);

    // Recalulate playable cells
    playable_cells_ = GetPlayableCells(!player_);

    // Change player if there are vaild moves
    if(playable_cells_.size())
    {
        player_ = !player_;
    }

    // Update game board
    UpdateBoard();
}

bool Othello::isValidDir(cellpos pos, celldir dir, bool player)
{
    pos += dir;

    // Check that we didn't go off the board
    if(!isCellposOnBoard(pos))
    {
        return false;
    }

    // Check if cell is empty
    auto piece = pieces_.find(pos);
    if(piece == pieces_.end())
    {
        return false;
    }

    // Check if same color
    if(piece->second.type_ == player)
    {
        return false;
    }

    // Check if there is another of players pieces after the !players piece
    pos += dir;

    while(isCellposOnBoard(pos))
    {

        // If empty return false
        auto piece = pieces_.find(pos);
        if(piece == pieces_.end())
        {
            return false;
        }

        // If same color return true
        if(piece->second.type_ == player)
        {
            return true;
        }

        // Increment
        pos += dir;
    }

    // Cell is off board
    return false;
}

bool Othello::isCellposOnBoard(cellpos pos)
{
    if(pos.first >= board_size_ || pos.second >= board_size_)
        return false;
    else
        return true;
}

void Othello::FlipPieces(cellpos pos, bool player)
{
    for(auto dir : ALL_DIRS)
    {
        if(isValidDir(pos, dir, player))
        {
            cellpos new_pos = pos + dir;
            while(true)
            {
                auto it = pieces_.find(new_pos);
                if(it->second.type_ == player)
                {
                    break;
                }

                it->second.type_ = player;
                new_pos += dir;
            }
        }
    }
}
