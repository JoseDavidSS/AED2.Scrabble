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

string LetterNode::serialize() {
    StringBuffer sB;
    Writer<StringBuffer> writer(sB);
    this->serializer(writer);
    return sB.GetString();
}

template<typename Writer>
void LetterNode::serializer(Writer &writer) const {
    writer.StartObject();
    writer.String("letter");
    writer.String(this->letter.c_str());
    writer.String("point");
    writer.Int(this->point);
    writer.String("counter");
    writer.Int(this->counter);
    writer.String("next");
    if (this->next == nullptr){
        writer.Null();
        writer.EndObject();
    }else{
        writer.String(this->next->serialize().c_str());
        writer.EndObject();
    }
}
