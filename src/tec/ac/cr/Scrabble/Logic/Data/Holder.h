//
// Created by kevin on 19/03/19.
//

#ifndef SCRABBLE_HOLDER_H
#define SCRABBLE_HOLDER_H

#include <string>
#include "../rapidjson/prettywriter.h"
#include "../Lists/Letters/LetterList.h"
#include "../Lists/Dictionary/WordList.h"
#include "../Lists/Matrix/LastPlayList.h"

using namespace std;
using namespace rapidjson;

class Holder {

public:

    static Holder* getInstance();

    LetterList* letterList = nullptr;
    LastPlayList* lastPlayList = nullptr;

    bool getTurn();
    void setTurn(bool turn);
    int getPoints();
    void setPoints(int points);
    bool getValidatedPlay();
    void setValidatedPlay(bool validatedPlay);
    string getPlayerName();
    void setPlayerName(string playerName);
    int getCodeToEnter();
    void setCodetoEnter(int codeToEnter);
    string serialize();
    template<typename Writer>
    void serializer(Writer& writer) const;
    Holder* deserialize(const char* json);

private:

    Holder() = default;
    Holder(Holder const&) = default;
    Holder& operator = (Holder const&) = default;

    static Holder* holder;
    bool turn = false; //Este indica si es el turno del jugador o no
    bool validatedPlay = false; // Este indica si la jugada es validada por el server
    int points = 0; //Puntos del jugador
    string playerName = ""; //Nombre del jugador
    int codeToEnter = 0; //Codigo para ingresar a una partida o para crear una

};


#endif //SCRABBLE_HOLDER_H
