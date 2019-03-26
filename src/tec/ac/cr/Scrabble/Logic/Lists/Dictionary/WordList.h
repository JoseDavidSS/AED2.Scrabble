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

    WordList() = default;

    WordNode* head = nullptr;

    int getLenght();
    void setLenght(int lenght);
    void addWord(string word);
    bool searchWord(string word);
    bool checkWordsInList();

private:

    int lenght = 0;

};


#endif //SCRABBLE_WORDLIST_H
