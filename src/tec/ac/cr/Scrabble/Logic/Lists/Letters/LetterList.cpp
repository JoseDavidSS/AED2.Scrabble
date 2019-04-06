//
// Created by kevin on 24/03/19.
//

#include <string>
#include <iostream>
#include <QtCore/QJsonArray>
#include "LetterList.h"
#include "../../rapidjson/document.h"

using namespace std;

LetterList* LetterList::letterList = nullptr;

LetterList* LetterList::getInstance() {
    if (!letterList){
        letterList = new LetterList;
        letterList->letterSorter();
    }
    return letterList;
}

/**
 * Method to add letters to the list
 */
void LetterList::letterSorter() {
    insertNode("A", 1, 12);
    insertNode("E", 1, 12);
    insertNode("0", 1, 9);
    insertNode("I", 1, 6);
    insertNode("S", 1, 6);
    insertNode("N", 1, 5);
    insertNode("L", 1, 4);
    insertNode("R", 1, 5);
    insertNode("U", 1, 5);
    insertNode("T", 1, 4);
    insertNode("D", 2, 5);
    insertNode("G", 2, 2);
    insertNode("C", 3, 4);
    insertNode("B", 3, 2);
    insertNode("M", 3, 2);
    insertNode("P", 3, 2);
    insertNode("H", 4, 2);
    insertNode("F", 4, 1);
    insertNode("V", 4, 1);
    insertNode("Y", 4, 1);
    insertNode("Ch", 5, 1);
    insertNode("Q", 5, 1);
    insertNode("J", 8, 1);
    insertNode("Ll", 8, 1);
    insertNode("Ñ", 8, 1);
    insertNode("RR", 8, 1);
    insertNode("X", 8, 1);
    insertNode("Z", 10, 1);
    insertNode("", 0, 2);
}

int LetterList::getLenght() {
    return this->length;
}

void LetterList::setLenght(int lenght) {
    this->length = lenght;
}

/**
 * Method to add nodes to the list
 * @param letter that will be inserted to the list
 * @param points of the letter
 * @param counter of how many of that letter are
 */
void LetterList::insertNode(string letter, int points, int counter) {
    if (this->head == nullptr){
        this->head = new LetterNode(letter, points, counter);
        this->length++;
    }else{
        LetterNode* tmp = this->head;
        while (tmp->next != nullptr){
            tmp = tmp->next;
        }
        tmp->next = new LetterNode(letter, points, counter);
        this->length++;
    }
}

/**
 * Method that deletes a node from the list
 * @param letter that will be deleted from the list
 */
void LetterList::deleteNode(string letter) {
    if (this->head == nullptr){
        printf("Theres no node to delete");
    }else if(this->head->getLetter() == letter){
        this->head = this->head->next;
        this->length--;
    }else{
        LetterNode* tmp = this->head;
        while (tmp->next != nullptr){
            if (tmp->next->getLetter() == letter){
                tmp->next = tmp->next->next;
                this->length--;
                break;
            }else{
                tmp = tmp->next;
            }
        }
    }
}

/**
 * Method that prints the list
 */
void LetterList::printList() {
    if (this->head == nullptr){
        printf("Lista nula");
    }else{
        LetterNode* tmp = this->head;
        while (tmp != nullptr){
            cout << tmp->getLetter() << endl;
            tmp = tmp->next;
        }
    }
}

/**
 * Method that deserializes a LetterList from a json
 * @param json that have the data
 * @param nodesArray where all the list data is
 * @return LetterList that has the letters of the player
 */
LetterList* LetterList::read(const QJsonObject& json, const QJsonArray& nodesArray) {
    LetterList* parsedList = new LetterList();
    if (!nodesArray.empty()){
        for (int i = 0; i < nodesArray.size(); i++){
            QJsonObject node = nodesArray[i].toObject();
            LetterNode* tmp = new LetterNode();
            tmp->read(node);
            parsedList->insertNode(tmp->getLetter(), tmp->getPoints(), tmp->getCounters());
        }
        return parsedList;
    }else{
        parsedList->head = nullptr;
        return parsedList;
    }
}

/**
 * Method that serializes a LetterList
 * @param json where the list will be serialized
 * @param nodesArray this is a qt array that converts the linked list to a qt array and saves it
 * @return the serialized array
 */
QJsonArray& LetterList::write(QJsonObject& json, QJsonArray& nodesArray) const {
    if (this->head == nullptr){
        return nodesArray;
    }else{
        LetterNode* tmp = this->head;
        while (tmp != nullptr){
            QJsonObject node;
            tmp->write(node);
            nodesArray.append(node);
            tmp = tmp->next;
        }
        return nodesArray;
    }
}