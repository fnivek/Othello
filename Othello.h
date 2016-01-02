#ifndef OTHELLO_H
#define OTHELLO_H

#include <QMainWindow>
#include <QPainter>
#include <QVBoxLayout>

class Othello : public QMainWindow
{
    Q_OBJECT
    
public:
    Othello(QWidget *parent = 0);
    ~Othello();

private:
    // Graphics
    QPen pen_;
    QBrush brush_;
    //QPixmap pixmap_;

    // Game vars
    unsigned short int board_size_ = 8;

protected:
    // Graphics
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;
};

#endif // OTHELLO_H
