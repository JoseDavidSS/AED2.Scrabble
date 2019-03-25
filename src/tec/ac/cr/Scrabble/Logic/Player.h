//
// Created by jose on 24/03/19.
//

#ifndef SCRABBLE_PLAYER_H
#define SCRABBLE_PLAYER_H

#include "rapidjson/prettywriter.h" // for stringify JSON
#include <iostream>

using namespace std;
using namespace rapidjson;

class Player {

public:

    string name;
    string word;
    int firstRow;
    int firstCol;
    int lastRow;
    int lastCol;


    Player(string name);

    void setMessage(string word,int fRow,int fCol, int lRow,int lCol);

    template<typename Writer>
    void Serializer(Writer& writer) const;

    string serialize();

    void setName(const string &name);

    void setWord(const string &word);

    void setFirstRow(int firstRow);

    void setFirstCol(int firstCol);

    void setLastRow(int lastRow);

    void setLastCol(int lastCol);

    Player* deserealize(const char* json);

    string toString();
};

#endif //SCRABBLE_PLAYER_H
