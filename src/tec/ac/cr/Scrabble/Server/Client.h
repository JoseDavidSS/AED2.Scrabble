//
// Created by kevin on 16/03/19.
//

#ifndef SCRABBLE_CLIENT_H
#define SCRABBLE_CLIENT_H
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

class Client {

public:

    Client() = default;

    static int run();
    static int settingPort();
    static string settingIpAddress();

};


#endif //SCRABBLE_CLIENT_H
