//
// Created by Alejandro Ibarra on 2019-03-23.
//

#ifndef SCRABBLE_NODE_H
#define SCRABBLE_NODE_H

#include <iostream>

using namespace std;

class Node {

public:
    Node *next;
    Node *prev;
    string letter;
    int multiplier = 0;
};


#endif //SCRABBLE_NODE_H
