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

string Node::serialize() {
    StringBuffer sB;
    Writer<StringBuffer> writer(sB);
    this->serializer(writer);
    return sB.GetString();
}

template<typename Writer>
void Node::serializer(Writer &writer) const {
    writer.StartObject();
    writer.String("letter");
    writer.String(this->letter.c_str());
    writer.String("multiplier");
    writer.Int(this->multiplier);
    writer.String("id");
    writer.Int(this->id);
    writer.String("next");
    if (this->next == nullptr){
        writer.Null();
        writer.EndObject();
    }else{
        writer.String(this->next->serialize().c_str());
        writer.EndObject();
    }
}