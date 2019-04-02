//
// Created by kevin on 16/03/19.
//

#ifndef SCRABBLE_CLIENT_H
#define SCRABBLE_CLIENT_H
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

#include "../Logic/Data/Holder.h"

class Client {

public:

    static Client* getInstance();

    Holder* run(QJsonObject& json);

private:

    Client() = default;
    Client(Client const&)= default;
    Client& operator = (Client const&) = default;

    static Client* client;
    static int settingPort();
    static string settingIpAddress();

};


#endif //SCRABBLE_CLIENT_H
