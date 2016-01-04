#include "Othello.h"

const array<array<short, 2>, 4> Othello::CARDINAL_DIRS{{
        {{-1, 0}}, {{ 0,-1}},
        {{ 1, 0}}, {{ 0, 1}}
                                                         }};

const array<array<short, 2>, 8> Othello::ALL_DIRS{{
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
    cout << "GetPlayableCells\n";
    cellposset cells = cellposset();
    // Itterate through all pieces_
    for(auto&& p : pieces_)
    {
        auto&& piece = p.second;
        auto pos = p.first;
        cout << "Check " << pos.first << ',' << pos.second << endl;

        // If all four adjacent sides are full move on
        if(piece.surrounded_)
        {
            cout << "Piece surrounded\n";
            continue;
        }

        // Check if piece is player color
        if(piece.type_ == player)
        {
            cout << "Same color\n";
            continue;
        }

        // Check all neibours
        bool surrounded = true;
        for(auto dir : CARDINAL_DIRS)
        {
            cellpos new_pos = pos;
            new_pos.first += dir[0];
            new_pos.second += dir[1];
            cout << "Check niebour" << new_pos.first << ',' << new_pos.second << endl;

            // Check if new pos is on board
            if(!isCellposOnBoard(new_pos))
            {
                cout << "Off board\n";
                continue;
            }

            // if new pos is ocupied move on
            if(pieces_.count(new_pos))
            {
                cout << "Piece occupied\n";
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
                    cout << "Niebour" << new_pos.first << ',' << new_pos.second << " is vaild\n";
                    break;
                }
            }

            cout << "No valid dirs\n";

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

    // TODO: Flip pieces
    //...

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

bool Othello::isValidDir(cellpos pos, array<short, 2> dir, bool player)
{
    cout << "Check if dir" << dir[0] << ',' << dir[1] << " is valid for" << pos.first << ',' << pos.second << endl;
    pos.first += dir[0];
    pos.second += dir[1];

    cout << "Check " << pos.first << ',' << pos.second << endl;

    // Check that we didn't go off the board
    if(!isCellposOnBoard(pos))
    {
        cout << "Cell is off board\n";
        return false;
    }

    // Check if cell is empty
    auto piece = pieces_.find(pos);
    if(piece == pieces_.end())
    {
        cout << "Cell is empty\n";
        return false;
    }

    // Check if same color
    if(piece->second.type_ == player)
    {
        cout << "Cell is same color\n";
        return false;
    }

    // Check if there is another of players pieces after the !players piece
    pos.first += dir[0];
    pos.second +=dir[1];
    cout << "Check " << pos.first << ',' << pos.second << endl;

    while(isCellposOnBoard(pos))
    {

        // If empty return false
        auto piece = pieces_.find(pos);
        if(piece == pieces_.end())
        {
            cout << "Cell is empty\n";
            return false;
        }

        // If same color return true
        if(piece->second.type_ == player)
        {
            cout << "Valid direction\n";
            return true;
        }

        // Increment
        pos.first += dir[0];
        pos.second +=dir[1];
        cout << "Check " << pos.first << ',' << pos.second << endl;
    }

    // Cell is off board
    cout << "Cell is off board\n";
    return false;
}

bool Othello::isCellposOnBoard(cellpos pos)
{
    if(pos.first >= board_size_ || pos.second >= board_size_)
        return false;
    else
        return true;
}
