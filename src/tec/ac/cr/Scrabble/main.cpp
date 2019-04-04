#include "Server/Client.h"
#include "Logic/Lists/Matrix/List.h"
#include "Logic/Lists/Matrix/Matrix.h"
#include "Logic/Data/Holder.h"
#include "UI/menu.h"
#include "Server/ASync.h"

#include <iostream>
#include <QApplication>
#include <QtCore/QJsonDocument>

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
     matrix->checkPlay();

    ASync* async = new ASync();
    async->thread();
    string userInput1;
    string userInput2;
    string userInput3;
    Matrix* matrix = Matrix::getInstance();
    Holder* holder = Holder::getInstance();


    while (true){
        cout << "> ";
        getline(cin, userInput1);
        if (userInput1 == "ins"){
            while (true){
                cout << "> ";
                getline(cin, userInput1);
                cout << "> ";
                getline(cin, userInput2);
                cout << "> ";
                getline(cin, userInput3);
                if (userInput1 == "fin") {
                    break;
                }
                matrix->addIndex(userInput1, stoi(userInput2), stoi(userInput3));
                holder->lastPlayList = LastPlayList::getInstance();
            }
        }

    }
    */

    QApplication a(argc, argv);
        Menu w;
        w.show();

        return a.exec();

}

