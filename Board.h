#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPainter>

class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = 0);

private:
    // Graphics
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

    // Board vars
    unsigned short int board_size_ = 8;
    
signals:
    
public slots:
    
};

#endif // BOARD_H
