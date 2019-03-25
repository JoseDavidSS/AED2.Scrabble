//
// Created by chus on 18/03/19.
//
#include </home/chus/CLionProjects/Scrabble/src/tec/ac/cr/Scrabble/Logic/json.hpp>
#include <iostream>
#include "stdio.h"

#ifndef SCRABBLE_SERIALIZER_H
#define SCRABBLE_SERIALIZER_H


using json = nlohmann::json;
using namespace std;

class Serializer {
    json j = "{ \"happy\": true, \"pi\": 3.141 }"_json;
    string s = j.dump();    // {\"happy\":true,\"pi\":3.141}

    cout << j.dump(4) << std::endl;


};


#endif //SCRABBLE_SERIALIZER_H
