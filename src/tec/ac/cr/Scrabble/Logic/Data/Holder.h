//
// Created by kevin on 19/03/19.
//

#ifndef SCRABBLE_HOLDER_H
#define SCRABBLE_HOLDER_H

#include <string>
#include "../rapidjson/prettywriter.h"
#include "../Lists/LetterList.h"

using namespace std;
using namespace rapidjson;

class Holder {

public:

    static Holder* getInstance();

    LetterList* letterList = new LetterList();

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

private:

    Holder() = default;
    Holder(Holder const&) = default;
    Holder& operator = (Holder const&) = default;

    static Holder* holder;
    bool turn; //Este indica si es el turno del jugador o no
    bool validatedPlay; // Este indica si la jugada es validada por el server
    int points; //Puntos del jugador
    string playerName; //Nombre del jugador
    int codeToEnter; //Codigo para ingresar a una partida o para crear una
    //Matriz (lista de listas) del juego

};


#endif //SCRABBLE_HOLDER_H
