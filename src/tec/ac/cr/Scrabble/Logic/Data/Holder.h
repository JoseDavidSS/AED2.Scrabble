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
    static void setInstance(Holder* nholder);

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

    static Holder* read(const QJsonObject &json);
    void write(QJsonObject& json) const;

private:

    Holder() = default;
    Holder(Holder const&) = default;
    Holder& operator = (Holder const&) = default;

    static Holder* holder;
    bool turn = false;
    bool validatedPlay = false;
    int points = 0;
    string playerName = "";
    int codeToEnter = 0;

};


#endif //SCRABBLE_HOLDER_H
