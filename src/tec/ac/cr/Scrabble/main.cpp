#include "Server/Client.h"
#include "Logic/Lists/List.h"
#include "Logic/Lists/Matrix.h"
#include "Logic/Player.h"

#include <iostream>

using namespace std;

int main()
{
//    Player* p1 = new Player("Jose");
//    p1->setMessage("LEON",1,1,1,4);
//    p1->toString();
//    string json = p1->serialize();
//    cout<<json<<endl;
//    Player* p2 = p1->deserealize(json.c_str());
//    p2->toString();

    Matrix *matriz = Matrix::getInstance();
    matriz->display();

    cout << "Here's to the crazy ones" << endl;

//    Client client;
//    client.run();
    return 0;
}