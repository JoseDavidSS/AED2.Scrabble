#ifndef CONNECTWINDOW_H
#define CONNECTWINDOW_H

#include <QMainWindow>
#include "board.h"

namespace Ui {
class ConnectWindow;
}

class ConnectWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit ConnectWindow(QWidget *parent = nullptr);
    ~ConnectWindow();
    Holder* holder = Holder::getInstance();

public slots:
       void toBoard(bool isDark);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ConnectWindow *ui;
    Board *board;

private slots:
    void on_hostButton_clicked();
    void on_joinButton_clicked();
};

#endif // CONNECTWINDOW_H
