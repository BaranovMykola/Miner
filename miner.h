#ifndef MINER_H
#define MINER_H

#include <QMainWindow>

namespace Ui {
class Miner;
}

class Miner : public QMainWindow
{
    Q_OBJECT

public:
    explicit Miner(QWidget *parent = 0);
    ~Miner();

private:
    Ui::Miner *ui;
};

#endif // MINER_H
