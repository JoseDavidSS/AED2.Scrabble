#include "Server/Client.h"
#include "Logic/Lists/Matrix/List.h"
#include "Logic/Lists/Matrix/Matrix.h"
#include "Logic/Player.h"
#include "Logic/Data/Holder.h"
#include "UI/menu.h"

#include <iostream>
#include <QApplication>

using namespace std;

int main(int argc, char *argv[]){

    Matrix* matrix = Matrix::getInstance();
    matrix->display();
    matrix->addIndex("h", 1, 1);
    matrix->addIndex("o", 1, 2);
    matrix->addIndex("l", 1, 3);
    matrix->addIndex("a", 1, 4);
    matrix->display();
    matrix->addIndex("n", 2, 4);
    matrix->setLastPlayRow(0);
    matrix->setLastPlayColumn(0);
    matrix->addIndex("o", 3, 4);
    matrix->checkPlay();

//    Client client;
//    client.run();
    QApplication a(argc, argv);
        Menu w;
        w.show();

        return a.exec();
}
