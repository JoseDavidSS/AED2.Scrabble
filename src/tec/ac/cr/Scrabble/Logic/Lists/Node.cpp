//
// Created by kevin on 16/03/19.
//

#include "Node.h"

void Node::setLetter(string letter) {
    this->letter = letter;
}

string Node::getLetter() {
    return this->letter;
}

void Node::setPoints(int point) {
    this->point = point;
}
void Node::setCounters(int counter) {
    this->counter = counter;
}

int Node::getPoints() {
    return this->point;
}
int Node::getCounters() {
    return this->counter;
}