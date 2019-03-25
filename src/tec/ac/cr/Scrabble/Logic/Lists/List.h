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
        tail = nullptr;
        length = 0;
    }

    List* next = nullptr;
    int length;

    void add(string n, int id, int multiplier = 0);

    void display();

    Node* getHead();

    Node* index(int n);

private:
    Node *head,*tail;

};


#endif //SCRABBLE_LIST_H
