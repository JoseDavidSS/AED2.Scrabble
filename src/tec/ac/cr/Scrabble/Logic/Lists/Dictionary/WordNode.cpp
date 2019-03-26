//
// Created by kevin on 26/03/19.
//

#include "WordNode.h"

bool WordNode::getFound() {
    return this->found;
}

void WordNode::setFound(bool found) {
    this->found = found;
}

string WordNode::getWord() {
    return this->word;
}

void WordNode::setWord(string word) {
    this->word = word;
}