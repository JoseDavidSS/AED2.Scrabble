#include "Server/Client.h"
#include "Logic/Lists/List.h"
#include "Logic/Lists/Matrix.h"
#include "Logic/Player.h"
#include "Logic/Data/Holder.h"
#include "UI/menu.h"
#include "stdio.h"

#include <iostream>
#include <fstream>
#include <QApplication>

using namespace std;

int main(int argc, char *argv[]){

    Holder* holder = Holder::getInstance();
    holder->setTurn(false);
    holder->setPoints(1000);
    holder->setValidatedPlay(true);
    holder->setPlayerName("dasd");
    holder->setCodetoEnter(12345);
    string j = holder->serialize();
    cout << j << endl;

    /*

    // Prueba del super serializador de Chuz:
    {
        ifstream fin;
        fin.open("/home/chus/CLionProjects/Scrabble/src/tec/ac/cr/Scrabble/Logic/Lists/words_fixed_again.text");
        if(fin.fail())
        {
            cout << "No hay ni pinga.\n";
            exit(1);
        }
        string search;
        cout << "Ingrese algo"
                " ";
        cin  >> search;
        bool isFound=0;
        while(!fin.eof()) {
            string temp = "";
            getline(fin, temp);
            for (int i = 0; i < search.size(); i++) {
                if (temp[i] == search[i])
                    isFound = 1;
                else {
                    isFound = 0;
                    break;
                }
            }

            if (isFound == 1) {
                cout << "Su palabra si esta y es ";
                cout << temp;
                break;
            }
        }



        if(fin.eof()&&(!isFound))
        {
            cout << "Su palabra no existe F\n";
        }

        fin.close();

        return 0;
    }

    // Prueba del json de Jose:
    Player* p1 = new Player("Jose");
    p1->setMessage("LEON",1,1,1,4);
    p1->toString();
    string json = p1->serialize();
    cout<<json<<endl;
    Player* p2 = p1->deserealize(json.c_str());
    p2->toString();

    //Prueba del arbol de Chuz:
    Btree *tree = new Btree();

    tree->insert(10);
    tree->insert(6);
    tree->insert(14);
    tree->insert(5);
    tree->insert(8);
    tree->insert(11);
    tree->insert(18);

    tree->preorder_print();

    // Prueba del cliente de Kevin.
     Client client;
     client.run();

     */

    QApplication a(argc, argv);
        Menu w;
        w.show();

    cout << "Here's to the crazy ones" << endl;
        return a.exec();
}
