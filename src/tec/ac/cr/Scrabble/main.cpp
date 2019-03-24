#include "Server/Client.h"
#include "Logic/Lists/List.h"
#include "Logic/Lists/Matrix.h"

#include <iostream>

using namespace std;

int main()
{

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