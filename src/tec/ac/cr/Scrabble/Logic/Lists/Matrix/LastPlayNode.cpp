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

void LastPlayNode::read(const QJsonObject &json) {
    if (json.contains("letter") && json["letter"].isString()){
        letter = json["letter"].toString().toUtf8().constData();
    }if (json.contains("row") && json["row"].isDouble()){
        row = json["row"].toInt();
    }if (json.contains("column") && json["column"].isDouble()){
        column = json["column"].toInt();
    }
}

void LastPlayNode::write(QJsonObject &json) const {
    json["letter"] = QString::fromStdString(letter);
    json["row"] = row;
    json["column"] = column;
}