#include "Board.h"

Board::Board(QWidget *parent) :
    QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

void Board::paintEvent(QPaintEvent*)
{
    switch (view_)
    {
    case PAINTER:
        RenderPainter();
        break;
    default:
        RenderPainter();
    }
}

void Board::SetView(view_type v)
{
    view_ = v;
}

void Board::RenderPainter()
{
    QPainter painter(this);

    // Draw backround
    painter.setBrush(QBrush(Qt::green));
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));

    // Draw lines
    painter.setPen(QPen());
    QVector<QLine> lines((board_size_ - 1) * 2);

    float x_diff = width() / board_size_;
    float x = x_diff;
    for(int iii = 0; iii < (board_size_ - 1); ++iii)
    {
        lines.append(QLine(x, 0, x, (height() - 1)));
        x += x_diff;
    }

    float y_diff = height() / board_size_;
    float y = y_diff;
    for(int iii = 0; iii < (board_size_ - 1); ++iii)
    {
        lines.append(QLine(0, y, (width() - 1), y));
        y += y_diff;
    }

    painter.drawLines(lines);

    // Draw Game pieces
    for(auto&& p : gs_.pieces_)
    {
        QRectF rec(x_diff * p.first.second, y_diff * p.first.first, x_diff, y_diff);
        if(p.second.type_ == Cell::WHITE)
        {
            painter.setBrush(QBrush(Qt::white));
        }
        else
        {
            painter.setBrush(QBrush(Qt::black));
        }

        painter.drawEllipse(rec);
    }

    // Draw playable cells
    painter.setBrush(Qt::yellow);
    for( auto&& c : gs_.playablecells_)
    {
        QRectF rec(x_diff * c.second, y_diff * c.first, x_diff, y_diff);
        painter.drawRect(rec);
    }
}

cellpos Board::GetCell(int x, int y)
{
    unsigned short column = x * board_size_ / width();
    unsigned short row = y * board_size_ / height();
    return cellpos(row, column);
}


void Board::mousePressEvent(QMouseEvent* event)
{
    if(event->button() != Qt::LeftButton)
        return;

    // Get and send cell to controller
    emit BoardClicked(GetCell(event->x(), event->y()));
}


void Board::SetBoardSize(unsigned short size)
{
    if((size % 2) || (size < 4))
        return;

    board_size_ = size;
}

void Board::ModelUpdated(GameState gs)
{
    gs_ = gs;
    update();
}
