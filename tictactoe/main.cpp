#include "mainwindow.h"

#include <QApplication>

#include "board.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Board board(Entry::X);
    MainWindow window(nullptr,&board);

    window.show();
    return a.exec();
}
