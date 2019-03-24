#include "Server/Client.h"
#include "Logic/Lists/List.h"
#include "Logic/Lists/Matrix.h"
#include "Logic/Player.h"

#include <iostream>

using namespace std;

int main()
{
    Player* p1 = new Player("Jose");
    p1->setMessage("LEON",1,1,1,4);
    p1->toString();
    string json = p1->serialize();
    cout<<json<<endl;
    Player* p2 = p1->deserealize(json.c_str());
    p2->toString();

    // Create test lists
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

//    Client client;
//    client.run();
    return 0;
}