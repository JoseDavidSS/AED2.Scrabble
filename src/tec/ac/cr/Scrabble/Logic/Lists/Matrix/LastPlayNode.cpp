//
// Created by kevin on 26/03/19.
//

#include "LastPlayNode.h"
#include "../../rapidjson/document.h"

string LastPlayNode::getLetter() {
    return this->letter;
}

void LastPlayNode::setLetter(string letter) {
    this->letter = letter;
}

int LastPlayNode::getRow() {
    return this->row;
}

void LastPlayNode::setRow(int i) {
    this->row = i;
}

int LastPlayNode::getColumn() {
    return this->column;
}

void LastPlayNode::setColumn(int j) {
    this->column = j;
}

string LastPlayNode::serialize() {
    StringBuffer sB;
    Writer<StringBuffer> writer(sB);
    this->serializer(writer);
    return sB.GetString();
}

template<typename Writer>
void LastPlayNode::serializer(Writer &writer) const {
    writer.StartObject();
    writer.String("letter");
    writer.String(this->letter.c_str());
    writer.String("row");
    writer.Int(this->row);
    writer.String("column");
    writer.Int(this->column);
    writer.String("next");
    if (this->next == nullptr){
        writer.Null();
        writer.EndObject();
    }else{
        writer.String(this->next->serialize().c_str());
        writer.EndObject();
    }
}

LastPlayNode* LastPlayNode::deserialize(const char *json) {
    LastPlayNode* parsedNode = new LastPlayNode();
    Document doc;
    doc.Parse(json);
    parsedNode->setLetter(doc["letter"].GetString());
    parsedNode->setRow(doc["row"].GetInt());
    parsedNode->setColumn(doc["column"].GetInt());
    if (doc["next"].IsNull()){
        parsedNode->next = nullptr;
        return parsedNode;
    }else{
        parsedNode->next = this->next->deserialize(doc["next"].GetString());
        return parsedNode;
    }
}