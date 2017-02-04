#include "miner.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Miner w;
    w.show();

    return a.exec();
}
