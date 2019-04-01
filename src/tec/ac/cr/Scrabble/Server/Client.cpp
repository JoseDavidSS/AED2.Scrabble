//
// Created by kevin on 16/03/19.
//

#include "Client.h"
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace std;

Client* Client::client = nullptr;

Client* Client::getInstance() {
    if (!client){
        client = new Client;
    }
    return client;
}

Holder* Client::run(Holder* holder) {

    //	Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        cout << "Error" << endl;
    }

    //	Create a hint structure for the server we're connecting with
    int port = 54000;
    string ipAddress = "127.0.0.1";

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

    //	Connect to the server on the socket
    int connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));
    if (connectRes == -1)
    {
        cout << "Error" << endl;
    }

    //	While loop:
    char buf[4096];
    string userInput;

    //		Enter lines of text
    cout << "> ";
    getline(cin, userInput);

    string jsonHolder = holder->serialize();

    //		Send to server
    int sendRes = send(sock, jsonHolder.c_str(), jsonHolder.size() + 1, 0);

    if (sendRes == -1)
    {
        cout << "No se pudo enviar al server! Ahhhh!\r\n";
    }

    //		Wait for response
    memset(buf, 0, 4096);
    int bytesReceived = recv(sock, buf, 4096, 0);

    if (bytesReceived == -1)
    {
        cout << "Hubo un error recibiendo del server\r\n";
    }
    else
    {
        //		Display response
        jsonHolder = string(buf, bytesReceived);
        cout << "SERVER> " << jsonHolder << "\r\n";
        holder = holder->deserialize(jsonHolder.c_str());
    }

    //	Close the socket
    close(sock);

}