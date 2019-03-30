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

    static LastPlayList* getInstance();

    LastPlayNode* head = nullptr;

    int getLenght();
    void setLenght(int lenght);
    void addPlay(string letter, int row, int column);
    void deletePlay(string letter, int row, int column);
    string serialize();
    template<typename Writer>
    void serializer(Writer& writer) const;
    LastPlayList* deserialize(const char* json);

private:

    LastPlayList() = default;
    LastPlayList(LastPlayList const&) = default;
    LastPlayList& operator = (LastPlayList const&) = default;

    static LastPlayList* lastPlayList;

    int lenght = 0;

};


#endif //SCRABBLE_LASTPLAYLIST_H
