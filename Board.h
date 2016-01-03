#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = 0);

    // View type
    enum view_type { PAINTER, TEST};

    // Set view
    void SetView(view_type v);

private:
    // Graphics
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;
    void RenderPainter();
    void RenderTest();

    // Board vars
    unsigned short int board_size_ = 8;
    view_type view_ = PAINTER;

    // Control
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    
signals:
    
public slots:
    
};

#endif // BOARD_H
