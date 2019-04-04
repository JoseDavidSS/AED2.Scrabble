#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu) {
    ui->setupUi(this);
}

Menu::~Menu() {
    delete ui;
}

void Menu::toConnectWindow() {
    connectWindow = new ConnectWindow(this);
    connectWindow->show();
}

void Menu::changeEvent(QEvent *e) {
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Menu::on_playButton_clicked() {
    toConnectWindow();
    hide();
}
