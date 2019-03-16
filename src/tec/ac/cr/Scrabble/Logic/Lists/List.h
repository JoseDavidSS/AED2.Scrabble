//
// Created by chus on 16/03/19.
//

#ifndef SCRABBLE_LIST_H
#define SCRABBLE_LIST_H


#include "Node.h"

class List {

public:

    List() = default;

    Node* head = nullptr;

    int getLenght();
    void setLenght(int lenght);
    void insertNode (string letter, int points, int counter);
    void deleteNode (string letter);
    void printList ();

private:

    int lenght = 0;

};


#endif //SCRABBLE_LIST_H
