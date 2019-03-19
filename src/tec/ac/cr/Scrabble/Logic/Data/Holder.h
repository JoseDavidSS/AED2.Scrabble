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
    bool turn;
    int points;
    string playerName;
    int codeToEnter;
    //Lista con las letras actuales del jugador
    //Matriz (lista de listas) del juego

};


#endif //SCRABBLE_HOLDER_H
