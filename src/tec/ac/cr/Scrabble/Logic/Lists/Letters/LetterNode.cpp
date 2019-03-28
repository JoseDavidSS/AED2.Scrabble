//
// Created by kevin on 24/03/19.
//

#include "LetterNode.h"
#include "../../rapidjson/document.h"

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

LetterNode* LetterNode::deserialize(const char *json) {
    LetterNode* parsedNode = new LetterNode();
    Document doc;
    doc.Parse(json);
    parsedNode->setLetter(doc["letter"].GetString());
    parsedNode->setPoints(doc["point"].GetInt());
    parsedNode->setCounters(doc["counter"].GetInt());
    if (doc["next"].IsNull()){
        parsedNode->next = nullptr;
        return parsedNode;
    }else{
        parsedNode->next = this->next->deserialize(doc["next"].GetString());
        return parsedNode;
    }
}
