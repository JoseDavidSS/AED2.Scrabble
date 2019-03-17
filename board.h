#ifndef BOARD_H
#define BOARD_H

#include <QMainWindow>

namespace Ui {
class Board;
}

class Board : public QMainWindow
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Board *ui;

private slots:
    void on_startButton_clicked();
};

#endif // BOARD_H
