//
// Created by jose on 16/03/19.
//

#ifndef SCRABBLE_ASYNC_H
#define SCRABBLE_ASYNC_H

#include "../Logic/Data/Holder.h"

using namespace std;

class ASync {

public:

    ASync() = default;

    static Holder* thread();
    static Holder* toSend();

};


#endif //SCRABBLE_ASYNC_H
