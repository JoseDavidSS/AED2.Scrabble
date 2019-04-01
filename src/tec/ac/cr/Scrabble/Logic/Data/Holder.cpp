//
// Created by kevin on 19/03/19.
//

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

string Holder::serialize() {
    StringBuffer sB;
    Writer<StringBuffer> writer(sB);
    this->serializer(writer);
    return sB.GetString();
}

template<typename Writer>
void Holder::serializer(Writer &writer) const {
    writer.StartObject();
    writer.String("turn");
    writer.Bool(this->turn);
    writer.String("validatedPlay");
    writer.Bool(this->validatedPlay);
    writer.String("points");
    writer.Int(this->points);
    writer.String("playerName");
    writer.String(this->playerName.c_str());
    writer.String("codeToEnter");
    writer.Int(this->codeToEnter);
    writer.String("letterList");
    if (this->letterList == nullptr){
        writer.Null();
        writer.String("lastPlayList");
        if (this->lastPlayList == nullptr){
            writer.Null();
            writer.EndObject();
        }else{
            writer.String(this->lastPlayList->serialize().c_str());
            writer.EndObject();
        }
    }else{
        writer.String(this->letterList->serialize().c_str());
        writer.String("lastPlayList");
        if (this->lastPlayList == nullptr){
            writer.Null();
            writer.EndObject();
        }else{
            writer.String(this->lastPlayList->serialize().c_str());
            writer.EndObject();
        }
    }
}

Holder* Holder::deserialize(const char *json) {
    Holder* parsedHolder = new Holder();
    Document doc;
    doc.Parse(json);
    parsedHolder->setTurn(doc["turn"].GetBool());
    parsedHolder->setValidatedPlay(doc["validatedPlay"].GetBool());
    parsedHolder->setPoints(doc["points"].GetInt());
    parsedHolder->setPlayerName(doc["playerName"].GetString());
    parsedHolder->setCodetoEnter(doc["codeToEnter"].GetInt());
    if (doc["letterList"].IsNull()){
        parsedHolder->letterList = nullptr;
        if (doc["lastPlayList"].IsNull()){
            parsedHolder->lastPlayList = nullptr;
            return parsedHolder;
        }else{
            parsedHolder->lastPlayList = this->lastPlayList->deserialize(doc["lastPlayList"].GetString());
            return parsedHolder;
        }
    }else{
        parsedHolder->letterList = this->letterList->deserialize(doc["letterList"].GetString());
        if (doc["lastPlayList"].IsNull()){
            parsedHolder->lastPlayList = nullptr;
            return parsedHolder;
        }else{
            parsedHolder->lastPlayList = this->lastPlayList->deserialize(doc["lastPlayList"].GetString());
            return parsedHolder;
        }
    }
}