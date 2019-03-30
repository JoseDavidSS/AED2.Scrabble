//
// Created by kevin on 26/03/19.
//

#ifndef SCRABBLE_WORDLIST_H
#define SCRABBLE_WORDLIST_H

#include <string>
#include "WordNode.h"

using namespace std;

class WordList {

public:

    static WordList* getInstance();

    WordNode* head = nullptr;

    int getLenght();
    void setLenght(int lenght);
    void addWord(string word);
    bool searchWord(string word);
    bool checkWordsInList();

private:

    WordList() = default;
    WordList(WordList const&)= default;
    WordList& operator = (WordList const&) = default;

    static WordList* wordList;

    int lenght = 0;

};


#endif //SCRABBLE_WORDLIST_H
