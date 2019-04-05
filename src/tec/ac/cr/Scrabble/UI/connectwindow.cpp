#include "connectwindow.h"
#include "ui_connectwindow.h"

ConnectWindow::ConnectWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConnectWindow) {
    ui->setupUi(this);
}

ConnectWindow::~ConnectWindow() {
    delete ui;
}

void ConnectWindow::toBoard() {
    board = new Board(this);
    board->show();
}

void ConnectWindow::changeEvent(QEvent *e) {
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void ConnectWindow::on_hostButton_clicked() {
    toBoard();
    hide();
}

void ConnectWindow::on_joinButton_clicked() {
    toBoard();
    hide();
}
