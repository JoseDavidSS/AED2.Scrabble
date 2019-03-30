//
// Created by Alejandro Ibarra on 2019-03-23.
//

#ifndef SCRABBLE_LIST_H
#define SCRABBLE_LIST_H


#include "Node.h"
#include <iostream>

using namespace std;

class List {

public:

    List() {

        head = nullptr;
        length = 0;
    }

    Node *head;
    List* next = nullptr;

    int getLenght();
    void setLenght(int lenght);
    void add(int id, int multiplier = 0);
    void display();
    Node* getHead();
    Node* index(int n);

private:

    int length;

};


#endif //SCRABBLE_LIST_H
