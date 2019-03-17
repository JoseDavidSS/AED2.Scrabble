#include "board.h"
#include "ui_board.h"

Board::Board(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
}

Board::~Board()
{
    delete ui;
}

void Board::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Board::on_startButton_clicked() {
    close();
}
