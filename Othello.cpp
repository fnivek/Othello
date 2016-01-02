#include "Othello.h"

Othello::Othello(QWidget *parent)
    : QWidget(parent),
      board_(new Board),
      test_(new QLabel)
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(board_);
    test_->setText("Test");
    layout->addWidget(test_);
    setLayout(layout);
}

Othello::~Othello()
{
    
}

