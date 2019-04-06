//
// Created by kevin on 26/03/19.
//

#include <iostream>
#include <QtCore/QJsonArray>
#include "LastPlayList.h"
#include "../../rapidjson/document.h"

LastPlayList* LastPlayList::lastPlayList = nullptr;

LastPlayList* LastPlayList::getInstance() {
    if (!lastPlayList){
        lastPlayList = new LastPlayList;
    }
    return lastPlayList;
}

void LastPlayList::setInstance(LastPlayList* nlastPlayList) {
    lastPlayList = nlastPlayList;
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

LastPlayList* LastPlayList::read(const QJsonObject& json, const QJsonArray& nodesArray) {
    LastPlayList* parsedList = new LastPlayList();
    if (!nodesArray.isEmpty()){
        for (int i = 0; i < nodesArray.size(); i++){
            QJsonObject node = nodesArray[i].toObject();
            LastPlayNode* tmp = new LastPlayNode();
            tmp->read(node);
            parsedList->addPlay(tmp->getLetter(), tmp->getRow(), tmp->getColumn());
        }
        return parsedList;
    }else{
        parsedList->head = nullptr;
        return parsedList;
    }
}

QJsonArray& LastPlayList::write(QJsonObject &json, QJsonArray& nodesArray) const {
    if (this->head == nullptr){
        return nodesArray;
    }else{
        LastPlayNode* tmp = this->head;
        while (tmp != nullptr){
            QJsonObject node;
            tmp->write(node);
            nodesArray.append(node);
            tmp = tmp->next;
        }
        return nodesArray;
    }
}