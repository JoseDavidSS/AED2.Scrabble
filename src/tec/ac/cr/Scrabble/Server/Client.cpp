/// \file
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
#include <QtCore/QJsonDocument>


using namespace std;

Client* Client::client = nullptr;

Client* Client::getInstance() {
    if (!client){
        client = new Client;
    }
    return client;
}

/**
 * Method that connects with the server
 * @param json with the holder that will be sent
 * @return a new holder instance with up to date data from the server
 */
Holder* Client::run(QJsonObject& json) {
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

    QJsonDocument doc(json);
    QByteArray ba = doc.toJson();
    QString qstr = QString(ba);
    string str = qstr.toStdString();

    //		Send to server
    int sendRes = send(sock, str.c_str(), str.size() + 1, 0);

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
        str = string(buf, 0, bytesReceived);
       // cout << "SERVER> " << str << "\r\n";
        QJsonDocument doc2 = QJsonDocument::fromJson(QByteArray(str.c_str()));
        json = doc2.object();
    }

    //	Close the socket
    close(sock);

    return Holder::read(json);
}

/**
 * Method tha reads the port from the properties.text
 * @return the port number
 */
int Client::settingPort() {
    ifstream fin;
    fin.open("/home/kevin/CLionProjects/Scrabble/src/tec/ac/cr/Scrabble/Server/properties.text");

    if (fin.fail()) {
        cout << "No hay ni pinga.\n";
        return 0;
    }

    string search = "port: ";
    bool isFound = false;
    string returningPuerto;
    int counter = 0;

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
            counter = i;
        }

        if (isFound) {

            for (int i = counter; i < 11; i++){
                returningPuerto += temp[i];
            }

            cout << "port encontrado:";
            cout << returningPuerto;
            cout << "\n";

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

/**
 * Method that reads the ip address from the properties.text
 * @return the ip address
 */
string Client::settingIpAddress(){
    ifstream fin;
    fin.open("/home/kevin/CLionProjects/Scrabble/src/tec/ac/cr/Scrabble/Server/properties.text");

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
        }

        if (isFound) {
            for (int i = contador+1; i < 25; i++){
                returningIpAddress += temp[i];
            }

            cout << "ipAddress encontrada:";
            cout << returningIpAddress;
            cout << "\n";

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