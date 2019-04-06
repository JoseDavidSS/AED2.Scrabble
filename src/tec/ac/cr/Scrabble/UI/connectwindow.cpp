#include "connectwindow.h"
#include "ui_connectwindow.h"
#include "../Server/ASync.h"

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
    holder->setPlayerName(ui->nameEntry->displayText().toStdString());
    holder->setPoints(ui->playerQuant->currentText().toInt());
    Holder::setInstance(ASync::thread());
    toBoard();
    hide();
}

void ConnectWindow::on_joinButton_clicked() {
    holder->setPlayerName(ui->nameEntry->displayText().toStdString());
    holder->setCodetoEnter(ui->roomEntry->displayText().toInt());
    Holder::setInstance(ASync::thread());
    toBoard();
    hide();
}
