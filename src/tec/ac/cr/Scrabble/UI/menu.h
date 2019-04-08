#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "connectwindow.h"
#include "marmota.h"

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

public slots:
       void toConnectWindow();
       void toMarmotaWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Menu *ui;
    ConnectWindow*connectWindow;
    marmota* marmotawindow;

private slots:
        void on_playButton_clicked();
        void on_infoButton_clicked();
};

#endif // MENU_H
