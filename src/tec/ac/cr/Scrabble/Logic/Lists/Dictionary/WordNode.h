//
// Created by kevin on 26/03/19.
//

#ifndef SCRABBLE_WORDNODE_H
#define SCRABBLE_WORDNODE_H

#include <string>

using namespace std;

class WordNode {

public:

    WordNode(string wrd){
        word = wrd;
    }

    string getWord();
    void setWord(string word);
    bool getFound();
    void setFound(bool found);

    WordNode* next = nullptr;

private:

    string word;
    bool found = false;

};


#endif //SCRABBLE_WORDNODE_H
