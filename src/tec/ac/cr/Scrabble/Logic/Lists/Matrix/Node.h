//
// Created by Alejandro Ibarra on 2019-03-23.
//

#ifndef SCRABBLE_NODE_H
#define SCRABBLE_NODE_H

#include <iostream>

using namespace std;

class Node {

public:

    Node* next;
    string letter;
    int multiplier = 0;
    int id;

    Node() = default;

    Node* getNext() const;

    void setNext(Node* next);

    const string& getLetter() const;

    void setLetter(const string& letter);

    int getMultiplier() const;

    void setMultiplier(int multiplier);

};


#endif //SCRABBLE_NODE_H
