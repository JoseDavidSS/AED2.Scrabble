//
// Created by kevin on 19/03/19.
//

#include <QtCore/QJsonArray>
#include "Holder.h"
#include "../rapidjson/document.h"

Holder* Holder::holder = nullptr;

Holder* Holder::getInstance() {
    if (!holder){
        holder = new Holder;
    }
    return holder;
}

bool Holder::getTurn() {
    return this->turn;
}

void Holder::setTurn(bool turn) {
    this->turn = turn;
}

int Holder::getPoints() {
    return this->points;
}

void Holder::setPoints(int points) {
    this->points = points;
}

bool Holder::getValidatedPlay() {
    return this->validatedPlay;
}

void Holder::setValidatedPlay(bool validatedPlay) {
    this->validatedPlay = validatedPlay;
}

string Holder::getPlayerName() {
    return this->playerName;
}

void Holder::setPlayerName(string playerName) {
    this->playerName = playerName;
}

int Holder::getCodeToEnter() {
    return this->codeToEnter;
}

void Holder::setCodetoEnter(int codeToEnter) {
    this->codeToEnter = codeToEnter;
}

Holder* Holder::read(const QJsonObject &json) {
    Holder* parsedHolder = new Holder();
    if (json.contains("turn") && json["turn"].isBool()){
        parsedHolder->setTurn(json["turn"].toBool());
    }if (json.contains("validatedPlay") && json["validatedPlay"].isBool()){
        parsedHolder->setValidatedPlay(json["validatedPlay"].toBool());
    }if (json.contains("points") && json["points"].isDouble()){
        parsedHolder->setPoints(json["points"].toInt());
    }if (json.contains("playerName") && json["playerName"].isString()){
        parsedHolder->setPlayerName(json["playerName"].toString().toUtf8().constData());
    }if (json.contains("codeToEnter") && json["codeToEnter"].isDouble()){
        parsedHolder->setCodetoEnter(json["codeToEnter"].toInt());
    }if (json.contains("letterList") && json["letterList"].isArray()){
        QJsonObject json1;
        parsedHolder->letterList = LetterList::read(json1, json["letterList"].toArray());
        if (json.contains("lastPlayList") && json["lastPlayList"].isArray()){
            QJsonObject json2;
            parsedHolder->lastPlayList = LastPlayList::read(json2, json["lastPlayList"].toArray());
            return parsedHolder;
        }else{
            parsedHolder->lastPlayList = nullptr;
            return parsedHolder;
        }
    }else{
        parsedHolder->letterList = nullptr;
        if (json.contains("lastPlayList") && json["lastPlayList"].isArray()){
            QJsonObject json2;
            parsedHolder->lastPlayList = LastPlayList::read(json2, json["lastPlayList"].toArray());
            return parsedHolder;
        }else{
            parsedHolder->lastPlayList = nullptr;
            return parsedHolder;
        }
    }
}

void Holder::write(QJsonObject &json) const {
    json["turn"] = turn;
    json["validatedPlay"] = validatedPlay;
    json["points"] = points;
    json["playerName"] = QString::fromStdString(playerName);
    json["codeToEnter"] = codeToEnter;
    if (letterList != nullptr){
        QJsonArray array1;
        QJsonObject json1;
        json["letterList"] = letterList->write(json1, array1);
        if (lastPlayList != nullptr){
            QJsonArray array2;
            QJsonObject json2;
            json["lastPlayList"] = lastPlayList->write(json2, array2);
        }else{
            json["lastPlayList"] = QString::fromStdString("null");
        }
    }else{
        json["letterList"] = QString::fromStdString("null");
        if (lastPlayList != nullptr){
            QJsonArray array2;
            QJsonObject json2;
            json["lastPlayList"] = lastPlayList->write(json2, array2);
        }else{
            json["lastPlayList"] = QString::fromStdString("null");
        }
    }
}