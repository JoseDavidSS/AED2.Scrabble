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
#include <fstream>
#include <sstream>


using namespace std;

int Client::run() {

    //	Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        return 1;
    }

    //	Create a hint structure for the server we're connecting with
    int port = settingPort();
    string ipAddress = settingIpAddress();

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

    //	Connect to the server on the socket
    int connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));
    if (connectRes == -1)
    {
        return 1;
    }

    //	While loop:
    char buf[4096];
    string userInput;

    //		Enter lines of text
    cout << "> ";
    getline(cin, userInput);

    //		Send to server
    int sendRes = send(sock, userInput.c_str(), userInput.size() + 1, 0);

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
        cout << "SERVER> " << string(buf, bytesReceived) << "\r\n";
    }

    //	Close the socket
    close(sock);

}

static int Client::settingPort() {

    ifstream fin;
    fin.open("/home/jose/CLionProjects/Scrabble/src/tec/ac/cr/Scrabble/Server/properties.text");

    if (fin.fail()) {
        cout << "No hay ni pinga.\n";
        return 0;
    }
    string search = "port: ";
    bool isFound = false;
    string returningPuerto;
    int contador=0;
    while (!fin.eof()) {
        string temp;
        getline(fin, temp);
        for (int i = 0; i < 6; i++) {
            if (temp[i] == search[i])
                isFound = true;
            else {
                isFound = false;
                break;
            }
            contador = i;
        }

        if (isFound) {
            for (int i = contador; i < 11; i++){
                returningPuerto += temp[i];
            }
            cout << "port encontrado\n";
            cout << returningPuerto;
            fin.close();

            stringstream toConvert(returningPuerto);

            int intReturningPort = 0;
            toConvert >> intReturningPort;
            return intReturningPort;
        }
    }

    if (fin.eof()) {
        cout << "Puerto no encontrado F\n";
        fin.close();
        return 0;
    }



}

static string Client::settingIpAddress(){
    ifstream fin;
    fin.open("/home/jose/CLionProjects/Scrabble/src/tec/ac/cr/Scrabble/Server/properties.text");

    if (fin.fail()) {
        cout << "No hay ni pinga.\n";
        return "";
    }
    string search = "ipAddress: ";
    bool isFound = false;
    string returningIpAddress;
    int contador=0;
    while (!fin.eof()) {
        string temp;
        getline(fin, temp);
        for (int i = 0; i < 11; i++) {
            if (temp[i] == search[i])
                isFound = true;
            else {
                isFound = false;
                break;
            }
            contador = i;
            cout << contador;
        }

        if (isFound) {
            for (int i = contador; i < 26; i++){
                returningIpAddress += temp[i];
                cout << i;
            }
            cout << "ipAddress encontrada";
            cout << returningIpAddress;
            fin.close();
            return returningIpAddress;
        }
    }

    if (fin.eof()) {
        cout << "Puerto no encontrado F\n";
        fin.close();
        return "fallo";
    }

}