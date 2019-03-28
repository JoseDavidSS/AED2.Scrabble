//
// Created by Alejandro Ibarra on 2019-03-23.
//

#include "Node.h"

string Node::getLetter(){
    return this->letter;
}

void Node::setLetter(string letter) {
    this->letter = letter;
}

int Node::getMultiplier(){
    return this->multiplier;
}

void Node::setMultiplier(int multiplier) {
    this->multiplier = multiplier;
}

int Node::getID() {
    return this->id;
}

void Node::setID(int id) {
    this->id = id;
}