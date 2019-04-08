#include "marmota.h"
#include "ui_marmota.h"

marmota::marmota(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::marmota)
{
    ui->setupUi(this);
}

marmota::~marmota()
{
    delete ui;
}
