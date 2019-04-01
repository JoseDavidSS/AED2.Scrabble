#include "Server/Client.h"
#include "Logic/Lists/Matrix/List.h"
#include "Logic/Lists/Matrix/Matrix.h"
#include "Logic/Data/Holder.h"
#include "UI/menu.h"
#include "Server/ASync.h"

#include <iostream>
#include <QApplication>

using namespace std;

int main(int argc, char *argv[]){

    /* Matrix* matrix = Matrix::getInstance();
     matrix->addIndex("h", 1, 1);
     matrix->addIndex("o", 1, 2);
     matrix->addIndex("l", 1, 3);
     matrix->addIndex("a", 1, 4);
     matrix->addIndex("n", 2, 4);
     matrix->addIndex("o", 3, 4);
     matrix->addIndex("o", 2, 3);
     matrix->addIndex("l", 3, 3);
     matrix->display();
     matrix->checkPlay();*/

    Holder* holder = Holder::getInstance();
    string jsonHolder = holder->serialize();
    cout << jsonHolder << endl;
    Client* client = Client::getInstance();
    client->run(holder);

    QApplication a(argc, argv);
        Menu w;
        w.show();

        return a.exec();

}
