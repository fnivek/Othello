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
    for(auto p : gs_.pieces_)
    {
        QRectF rec(x_diff * p.row_, y_diff * p.column_, x_diff, y_diff);
        if(p.type_ == Cell::WHITE)
        {
            painter.setBrush(QBrush(Qt::white));
        }
        else
        {
            painter.setBrush(QBrush(Qt::black));
        }

        painter.drawEllipse(rec);
    }
}

std::pair<unsigned short, unsigned short> Board::GetCell(int x, int y)
{
    x = x * board_size_ / width();
    y = y * board_size_ / height();
    return std::pair<unsigned short, unsigned short>(x, y);
}


void Board::mousePressEvent(QMouseEvent* event)
{
    if(event->button() != Qt::LeftButton)
        return;

    update();
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
