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

/**
 * Method that sends the holder instance to the server
 * @return the holder received from the server
 */
Holder* ASync::toSend() {
    Holder* holder = Holder::getInstance();
    QJsonObject json;
    holder->write(json);
    Client* client = Client::getInstance();
    return client->run(json);
}

/**
 * Method that activates an async thread that will manage the communication between client and server
 * @return
 */
Holder* ASync::thread() {
    future<Holder*> fn = async(launch::async, toSend);
    return fn.get();
}