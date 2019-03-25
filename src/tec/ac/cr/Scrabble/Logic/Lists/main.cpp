#include "../../Server/Client.h"
#include "List.h"
#include "Matrix.h"
#include "../Player.h"
#include "../Data/Holder.h"
#include "Btree.h"

#include <iostream>
#include "stdio.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
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


/*
    Btree *tree = new Btree();

    tree->insert(10);
    tree->insert(6);
    tree->insert(14);
    tree->insert(5);
    tree->insert(8);
    tree->insert(11);
    tree->insert(18);

    tree->preorder_print();
*/

    /*Holder* holder = Holder::getInstance();
    holder->setTurn(false);
    holder->setPoints(1000);
    holder->setValidatedPlay(true);
    holder->setPlayerName("dasd");
    holder->setCodetoEnter(12345);
    string j = holder->serialize();
    cout << j << endl;
     */

 /*   Player* p1 = new Player("Jose");
    p1->setMessage("LEON",1,1,1,4);
    p1->toString();
    string json = p1->serialize();
    cout<<json<<endl;
    Player* p2 = p1->deserealize(json.c_str());
    p2->toString();

    // Create test.txt lists
    List l;
    l.add("A");
    l.add("B");
    l.add("C");
    l.add("D");
    l.add("E");

    List o;
    o.add("F");
    o.add("G");
    o.add("H");
    o.add("I");
    o.add("J");

    List f;
    f.add("K");
    f.add("L");
    f.add("M");
    f.add("N");
    f.add("O");

    // Singleton Matrix
    Matrix& m = Matrix::getInstance();
    m.addRow(l);
    m.addRow(o);
    m.addRow(f);
    m.display();

    m.addIndex("hello", 3, 4);

    m.display();

    cout << "Here's to the crazy ones" << endl;
*/
//    Client client;
//    client.run();
    return 0;
}