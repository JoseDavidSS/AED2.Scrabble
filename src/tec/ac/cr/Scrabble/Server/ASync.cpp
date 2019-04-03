//
// Created by jose on 16/03/19.
//

#include "ASync.h"
#include "../Logic/Data/Holder.h"
#include "Client.h"
#include <pthread.h>
#include <future>
#include <iostream>

using namespace std;

int ASync::toDo() {
    Holder* holder = Holder::getInstance();
    QJsonObject json;
    holder->write(json);
    Client* client = Client::getInstance();
    client->run(json);
}

int ASync::aSyncFunction() {
    cout << "Main Thread: " << this_thread::get_id() << endl;
    future<int> fn = async(launch::async, toDo);
    int a = fn.get();
    return a;
}

