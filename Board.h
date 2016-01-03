#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <utility>

class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = 0);

    // View type
    enum view_type { PAINTER};

    // Set view
    void SetView(view_type v);

    // Set board size
    void SetBoardSize(unsigned short size);

private:
    // Graphics
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;
    void RenderPainter();

    // Board vars
    unsigned short int board_size_ = 8;
    view_type view_ = PAINTER;

    // Control
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    std::pair<unsigned short, unsigned short> GetCell(int x, int y);
    
signals:
    //void
    
public slots:
    
};

#endif // BOARD_H
