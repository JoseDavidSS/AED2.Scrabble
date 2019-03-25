//
// Created by kevin on 24/03/19.
//

#ifndef SCRABBLE_LETTERLIST_H
#define SCRABBLE_LETTERLIST_H

#include "LetterNode.h"

using namespace std;

class LetterList {

public:

    LetterList() = default;

    LetterNode* head = nullptr;

    int getLenght();
    void setLenght(int lenght);
    void insertNode (string letter, int points, int counter);
    void deleteNode (string letter);
    void printList ();
    void letterSorter();

private:

    int length = 0;

};


#endif //SCRABBLE_LETTERLIST_H
