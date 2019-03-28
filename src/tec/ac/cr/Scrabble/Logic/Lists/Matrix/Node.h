//
// Created by Alejandro Ibarra on 2019-03-23.
//

#ifndef SCRABBLE_NODE_H
#define SCRABBLE_NODE_H

#include <iostream>

using namespace std;

class Node {

public:

    Node() = default;

    Node* next;

    string getLetter();
    void setLetter(string letter);
    int getMultiplier();
    void setMultiplier(int multiplier);
    int getID();
    void setID(int id);

private:

    string letter;
    int multiplier = 0;
    int id;

};


#endif //SCRABBLE_NODE_H
