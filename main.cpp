#include "Othello.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Othello w;
    w.show();
    
    return a.exec();
}
