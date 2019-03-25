//
// Created by kevin on 24/03/19.
//

#ifndef SCRABBLE_LETTERLIST_H
#define SCRABBLE_LETTERLIST_H

#include "LetterNode.h"
#include "../rapidjson/prettywriter.h"

using namespace std;
using namespace rapidjson;

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
    string serialize();
    template<typename Writer>
    void serializer(Writer& writer) const;

private:

    int length = 0;

};


#endif //SCRABBLE_LETTERLIST_H
