//
// Created by jose on 24/03/19.
//

#include "rapidjson/prettywriter.h" // for stringify JSON
#include "rapidjson/stringbuffer.h"
#include "rapidjson/document.h"
#include "Player.h"

Player::Player(string name) {
    this->name = name;
    firstRow = 0;
    firstCol = 0;
    lastRow = 0;
    lastCol = 0;
}

void Player::setMessage(string word, int fRow,int fCol,int lRow, int lCol) {
    this-> word = word;
    this-> firstRow = fRow;
    this-> firstCol = fCol;
    this-> lastRow = lRow;
    this-> lastCol = lCol;
}

template <typename Writer>
void Player::Serializer(Writer &writer) const {

    writer.StartObject();
    writer.String("name");
    writer.String(name.c_str());
    writer.String("word");
    writer.String(word.c_str());
    writer.String("firstRow");
    writer.Int(firstRow);
    writer.String("firstCol");
    writer.Int(firstCol);
    writer.String("lastRow");
    writer.Int(lastRow);
    writer.String("lastCol");
    writer.Int(lastCol);
    writer.EndObject();
}

string Player::serialize() {
    StringBuffer sB;
    Writer<StringBuffer> writer(sB);
    Serializer(writer);
    return sB.GetString();
}

Player* Player::deserealize(const char* json) {

    Player* parsedPlayer = new Player("default");
    Document doc;
    doc.Parse(json);
    parsedPlayer->setName(doc["name"].GetString());
    parsedPlayer->setWord(doc["word"].GetString());
    parsedPlayer->setFirstRow(doc["firstRow"].GetInt());
    parsedPlayer->setFirstCol(doc["firstCol"].GetInt());
    parsedPlayer->setLastRow(doc["lastRow"].GetInt());
    parsedPlayer->setLastCol(doc["lastCol"].GetInt());

    return parsedPlayer;
}

void Player::setName(const string &name) {
    Player::name = name;
}

void Player::setWord(const string &word) {
    Player::word = word;
}

void Player::setFirstRow(int firstRow) {
    Player::firstRow = firstRow;
}

void Player::setFirstCol(int firstCol) {
    Player::firstCol = firstCol;
}

void Player::setLastRow(int lastRow) {
    Player::lastRow = lastRow;
}

void Player::setLastCol(int lastCol) {
    Player::lastCol = lastCol;
}

string Player::toString(){
    cout<<"Player[\n name: "<<name<<"\n word: "<<word<<endl;
    printf(" fr: %d\n fc: %d\n lr: %d\n lc: %d\n]\n",firstRow,firstCol,lastRow,lastCol);
}