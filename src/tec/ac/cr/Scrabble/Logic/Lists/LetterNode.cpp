//
// Created by kevin on 24/03/19.
//

#include "LetterNode.h"

void LetterNode::setLetter(string letter) {
    this->letter = letter;
}

string LetterNode::getLetter() {
    return this->letter;
}

void LetterNode::setPoints(int point) {
    this->point = point;
}

int LetterNode::getPoints() {
    return this->point;
}

void LetterNode::setCounters(int counter) {
    this->counter = counter;
}

int LetterNode::getCounters() {
    return this->counter;
}

