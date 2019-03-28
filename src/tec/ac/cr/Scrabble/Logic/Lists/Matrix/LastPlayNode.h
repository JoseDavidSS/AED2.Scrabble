//
// Created by kevin on 26/03/19.
//

#ifndef SCRABBLE_LASTPLAYNODE_H
#define SCRABBLE_LASTPLAYNODE_H

#include <string>
#include "../../rapidjson/prettywriter.h"

using namespace std;
using namespace rapidjson;

class LastPlayNode {

public:

    LastPlayNode(string lttr, int i, int j){
        letter = lttr;
        row = i;
        column = j;
    }

    LastPlayNode() = default;

    LastPlayNode* next = nullptr;

    string getLetter();
    void setLetter(string letter);
    int getRow();
    void setRow(int i);
    int getColumn();
    void setColumn(int j);
    string serialize();
    template<typename Writer>
    void serializer(Writer& writer) const;
    LastPlayNode* deserialize(const char* json);

private:

    string letter;
    int row;
    int column;

};


#endif //SCRABBLE_LASTPLAYNODE_H
