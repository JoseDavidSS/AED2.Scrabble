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

Holder* ASync::toSend() {
    Holder* holder = Holder::getInstance();
    holder->setPoints(2);
    holder->setPlayerName("Kevin");
    QJsonObject json;
    holder->write(json);
    Client* client = Client::getInstance();
    return client->run(json);
}

Holder* ASync::thread() {
    cout << "Main Thread: " << this_thread::get_id() << endl;
    future<Holder*> fn = async(launch::async, toSend);
    return fn.get();
}

Holder* ASync::toSend2() {
    Holder* holder = Holder::getInstance();
    QJsonObject json;
    holder->write(json);
    Client* client = Client::getInstance();
    return client->run(json);
}

Holder* ASync::thread2() {
    cout << "Main Thread: " << this_thread::get_id() << endl;
    future<Holder*> fn = async(launch::async, toSend2);
    return fn.get();
}