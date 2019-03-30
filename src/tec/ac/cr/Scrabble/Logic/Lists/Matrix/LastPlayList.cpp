//
// Created by kevin on 26/03/19.
//

#include <iostream>
#include "LastPlayList.h"
#include "../../rapidjson/document.h"

LastPlayList* LastPlayList::lastPlayList = nullptr;

LastPlayList* LastPlayList::getInstance() {
    if (!lastPlayList){
        lastPlayList = new LastPlayList;
    }
    return lastPlayList;
}

int LastPlayList::getLenght() {
    return this->lenght;
}

void LastPlayList::setLenght(int lenght) {
    this->lenght = lenght;
}

void LastPlayList::addPlay(string letter, int row, int column) {
    if (this->head == nullptr){
        this->head = new LastPlayNode(letter, row, column);
        this->lenght++;
    }else{
        LastPlayNode* tmp = this->head;
        while (tmp->next){
            tmp = tmp->next;
        }
        tmp->next = new LastPlayNode(letter, row, column);
        this->lenght++;
    }
}

void LastPlayList::deletePlay(string letter, int row, int column) {
    if (this->head == nullptr){
        cout << "Nada que borrar" << endl;
    }if (this->head->getLetter() == letter && this->head->getRow() == row && this->head->getColumn() == column){
        this->head = this->head->next;
    }else{
        LastPlayNode* tmp = this->head;
        while (tmp->next != nullptr){
            if (tmp->next->getLetter() == letter && tmp->next->getRow() == row && tmp->next->getColumn() == column){
                tmp->next = tmp->next->next;
                break;
            }else{
                tmp = tmp->next;
            }
        }
    }
}

string LastPlayList::serialize() {
    StringBuffer sB;
    Writer<StringBuffer> writer(sB);
    this->serializer(writer);
    return sB.GetString();
}

template<typename Writer>
void LastPlayList::serializer(Writer &writer) const {
    writer.StartObject();
    writer.String("lenght");
    writer.Int(this->lenght);
    writer.String("head");
    if (this->head == nullptr){
        writer.Null();
        writer.EndObject();
    }else{
        writer.String(this->head->serialize().c_str());
        writer.EndObject();
    }
}

LastPlayList* LastPlayList::deserialize(const char *json) {
    LastPlayList* parsedList = new LastPlayList();
    Document doc;
    doc.Parse(json);
    parsedList->setLenght(doc["lenght"].GetInt());
    if (doc["head"].IsNull()){
        parsedList->head = nullptr;
        return parsedList;
    }else{
        parsedList->head = this->head->deserialize(doc["head"].GetString());
        return parsedList;
    }
}