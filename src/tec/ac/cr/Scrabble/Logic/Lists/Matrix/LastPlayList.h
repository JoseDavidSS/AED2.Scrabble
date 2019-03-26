//
// Created by kevin on 26/03/19.
//

#ifndef SCRABBLE_LASTPLAYLIST_H
#define SCRABBLE_LASTPLAYLIST_H

#include "LastPlayNode.h"
#include <string>
#include "../../rapidjson/prettywriter.h"

using namespace std;
using namespace rapidjson;

class LastPlayList {

public:

    LastPlayList() = default;

    LastPlayNode* head = nullptr;

    int getLenght();
    void setLenght(int lenght);
    void addPlay(string letter, int row, int column);
    void deletePlay(string letter, int row, int column);
    string serialize();
    template<typename Writer>
    void serializer(Writer& writer) const;

private:

    int lenght = 0;

};


#endif //SCRABBLE_LASTPLAYLIST_H
