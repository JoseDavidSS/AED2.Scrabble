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

    Holder* holder = Holder::getInstance();
    holder->setTurn(false);
    holder->setPoints(1000);
    holder->setValidatedPlay(true);
    holder->setPlayerName("dasd");
    holder->setCodetoEnter(12345);
    holder->letterList->insertNode("a", 1, 10);
    holder->letterList->insertNode("b", 21, 12);
    holder->letterList->insertNode("c", 21, 12);
    holder->lastPlayList->addPlay("a", 1, 1);
    holder->lastPlayList->addPlay("b", 2, 2);
    holder->lastPlayList->addPlay("c", 21, 34);
    string j = holder->serialize();
    cout << j << endl;
    holder = holder->deserialize(j.c_str());

 /*   Player* p1 = new Player("Jose");
    p1->setMessage("LEON",1,1,1,4);
    p1->toString();
    string json = p1->serialize();
    cout<<json<<endl;
    Player* p2 = p1->deserealize(json.c_str());
    p2->toString();

    cout << "Here's to the crazy ones" << endl;
*/
//    Client client;
//    client.run();
    QApplication a(argc, argv);
        Menu w;
        w.show();

        return a.exec();
}
