//
// Created by kevin on 19/03/19.
//

#ifndef SCRABBLE_HOLDER_H
#define SCRABBLE_HOLDER_H

#include <string>

using namespace std;

class Holder {

public:

    static Holder* getInstance();

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
    //Lista con las letras actuales del jugador
    //Matriz (lista de listas) del juego

};


#endif //SCRABBLE_HOLDER_H
