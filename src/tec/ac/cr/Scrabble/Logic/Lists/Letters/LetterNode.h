//
// Created by kevin on 24/03/19.
//

#ifndef SCRABBLE_LETTERNODE_H
#define SCRABBLE_LETTERNODE_H

#include <string>
#include "../../rapidjson/prettywriter.h"

using namespace std;
using namespace rapidjson;

class LetterNode {

public:

    LetterNode(string letters, int points, int counters){
        letter = letters;
        point = points;
        counter = counters;
    }

    LetterNode() = default;

    LetterNode* next = nullptr;

    // Methods
    void setLetter(string letter);
    string getLetter();
    void setPoints(int point);
    int getPoints();
    void setCounters(int counter);
    int getCounters();
    string serialize();
    template<typename Writer>
    void serializer(Writer& writer) const;
    LetterNode* deserialize(const char* json);

private:

    string letter;
    int point;
    int counter;

};


#endif //SCRABBLE_LETTERNODE_H
