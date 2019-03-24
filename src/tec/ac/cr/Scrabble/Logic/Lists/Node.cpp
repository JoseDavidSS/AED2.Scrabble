//
// Created by Alejandro Ibarra on 2019-03-23.
//

#include "Node.h"

Node *Node::getNext() const {
    return next;
}

void Node::setNext(Node *next) {
    Node::next = next;
}

const string &Node::getLetter() const {
    return letter;
}

void Node::setLetter(const string &letter) {
    Node::letter = letter;
}

int Node::getMultiplier() const {
    return multiplier;
}

void Node::setMultiplier(int multiplier) {
    Node::multiplier = multiplier;
}
