//
// Created by kevin on 19/03/19.
//

#include "Holder.h"

Holder* Holder::holder = nullptr;

Holder* Holder::getInstance() {
    if (!holder){
        holder = new Holder;
    }
    return holder;
}
