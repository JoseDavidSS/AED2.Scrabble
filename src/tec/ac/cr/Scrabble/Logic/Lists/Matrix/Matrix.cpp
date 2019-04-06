//
// Created by Alejandro Ibarra on 2019-03-23.
//

#include "Matrix.h"
#include "LastPlayList.h"
#include "../Dictionary/WordList.h"
#include "../../Data/Holder.h"
#include <unordered_set>
#include <QVector>

Matrix* Matrix::matrix = nullptr;

/**
* Gets Singleton instance of Matrix. Default is 15x15 board.
* @return Matrix instance
*/
Matrix* Matrix::getInstance() {
    if (!matrix) {
        matrix = new Matrix;
        matrix->initialize();
        matrix->assignMultipliers();
    }
    return matrix;
}

void Matrix::setInstance(Matrix* nmatrix) {
    matrix = nmatrix;
}

int Matrix::getLenght() {
    return this->length;
}

void Matrix::setLenght(int lenght) {
    this->length = lenght;
}

int Matrix::getRows() {
    return this->rows;
}

void Matrix::setRows(int rows) {
    this->rows = rows;
}

int Matrix::getColumns() {
    return this->columns;
}

void Matrix::setColumns(int columns) {
    this->columns = columns;
}

int Matrix::getLastPlayRow() {
    return this->lastPlayRow;
}

void Matrix::setLastPlayRow(int row) {
    this->lastPlayRow = row;
}

int Matrix::getLastPlayColumn() {
    return this->lastPlayColumn;
}

void Matrix::setLastPlayColumn(int column) {
    this->lastPlayColumn = column;
}

int Matrix::getPreLastPlayRow() {
    return this->preLastPlayRow;
}

void Matrix::setPreLastPlayRow(int row) {
    this->preLastPlayRow = row;
}

int Matrix::getPreLastPlayColumn() {
    return this->preLastPlayColumn;
}

void Matrix::setPreLastPlayColumn(int column) {
    this->preLastPlayColumn = column;
}

//! Add a new value to list.
//! \param list that will be added
void Matrix::addRow(List* list) {
    if (this->head == nullptr) {
        this->head = list;
        this->length++;
    }else {
        List* tmp = this->head;
        while (tmp->next != nullptr){
            tmp = tmp->next;
        }
        tmp->next = list;
        this->length++;
    }
}

//! Adds a specific value in position.
//! \param letter string to add to position
//! \param i int of row
//! \param j int of column
void Matrix::addIndex(string letter, int i, int j) {
    Node* pos = index(i, j);
    pos->setLetter(letter);
    LastPlayList* lastPlayList = LastPlayList::getInstance();
    lastPlayList->addPlay(letter, i, j);
    LastPlayList::setInstance(lastPlayList);
    Holder::getInstance()->lastPlayList = lastPlayList;
    this->preLastPlayRow = this->lastPlayRow;
    this->preLastPlayColumn = this->lastPlayColumn;
    this->lastPlayRow = i;
    this->lastPlayColumn = j;
}

//! Method that deletes a letter from the matrix
//! \param letter that will be deleted
//! \param i row where the letter is
//! \param j column where the letter is
void Matrix::deleteIndex(string letter, int i, int j) {
    Node* pos = index(i, j);
    pos->setLetter("");
    LastPlayList* lastPlayList = LastPlayList::getInstance();
    lastPlayList->deletePlay(letter, i, j);
}


//! Assigns multipliers to nodes based on default Scrabble board.
void Matrix::assignMultipliers() {
    List* currentList = this->head;
    Node* tmp = this->head->getHead();
    unordered_set<int> DL = {4, 12, 37, 39, 46, 53, 60, 93, 97, 99, 103, 109, 117,
                             123, 127, 129, 133, 166, 173, 180, 187, 189, 214, 222};
    unordered_set<int> DW = {17, 29, 33, 43, 49, 57, 65, 71, 155, 161, 169, 177, 183, 193, 197, 209};
    unordered_set<int> TL = {21, 25, 77, 81, 85, 89, 137, 141, 145, 149, 201, 203};
    unordered_set<int> TW = {1, 8, 15, 106, 120, 211, 218, 225};
    while (currentList != nullptr) {
        while (tmp != nullptr) {
            if (DL.count(tmp->getID())) {
                tmp->setMultiplier(1);
            } else if (DW.count(tmp->getID())) {
                tmp->setMultiplier(2);
            } else if (TL.count(tmp->getID())) {
                tmp->setMultiplier(3);
            } else if (TW.count(tmp->getID())) {
                tmp->setMultiplier(4);
            }
            tmp = tmp->next;
        }
        currentList = currentList->next;
        if (currentList != nullptr) {
            tmp = currentList->getHead();
        }
    }
}

//! Displays list as string.
void Matrix::display() {
    List* tmp = this->head;
    while (tmp != nullptr) {
        tmp->display();
        tmp = tmp->next;
    }
}

//! Converts letter id to coordinates x and y in matrix.
//! \param id int of position to delete
//! \return
QVector<int>* Matrix::idToCoordinates(int id) {
    int row = 0;
    int column = -1;
    QVector<int>* result = new QVector<int>;

    while (id != 0) {
        if (column == 14) {
            row ++;
            column = -1;
        }
        column++;
        id --;
    }
    result->append(row);
    result->append(column);
    return result;
}

//! Finds the node with a specific index.
//! \param i row
//! \param j column
//! \return *Node
Node* Matrix::index(int i, int j) {
    List* tmp = head;
    int counter = 0;
    while (counter != i) {
        tmp = tmp->next;
        counter++;
    }
    Node* result = tmp->index(j);
    return result;
}

//! Initializes empty 15x15 matrix with preset multipliers.
void Matrix::initialize() {
    int rows = 15;
    int columns = 15;
    int columnsBackup = columns;
    int n = 1;

    while (rows != 0) {
        if (this->head == nullptr) {
            this->head = new List();
            while (columns != 0){
                this->head->add(n);
                n++;
                columns--;
            }
        } else {
            List* tmp = this->head;
            while (tmp->next != nullptr) {
                tmp = tmp->next;
            }
            tmp->next = new List();
            while (columns != 0){
                tmp->next->add(n);
                n++;
                columns--;
            }
        }
        rows--;
        columns = columnsBackup;
        this->length++;
    }
}

//! Method that checks if all the letters that where put in the matrix in the last turn are all in the same row or column
//! \param lastPlayList that has the last play
//! \return a boolean indicating if either they are or not
bool Matrix::checkPlay() {
    if (preLastPlayColumn == 0 && preLastPlayRow == 0){
        this->searchWords(lastPlayRow, lastPlayColumn);
        return true;
    }else{
        bool horizontal = true;
        bool vertical = false;
        if (lastPlayRow == preLastPlayRow){
            horizontal = true;
        }if (lastPlayColumn == preLastPlayColumn){
            vertical = true;
        }if (!horizontal && !vertical){
            return false;
        }else{
            this->searchWords(lastPlayRow, lastPlayColumn);
            return true;
        }
    }

}

//! Method that searchs the words that where formed in the last turn
//! \param row where the letter is
//! \param column where the letter is
void Matrix::searchWords(int row, int column) {
    string word;
    WordList* wordList = WordList::getInstance();
    int i = row - 1;
    int j = column - 1;
    bool horizontal = false;
    bool vertical = false;
    Node* posva = index(i, column);
    Node* posvp = index(i + 2, column);
    Node* posha = index(row, j);
    Node* poshp = index(row, j + 2);
    if (!posha->getLetter().empty() || !poshp->getLetter().empty()){
        horizontal = true;
    }if (!posva->getLetter().empty() || !posvp->getLetter().empty()){
        vertical = true;
    }if (!horizontal && !vertical){
        cout << "Nel" << endl;
    }else{
        string tmp;
        if (vertical){
            while (i != -1){
                if (!index(i, column)->getLetter().empty()){
                    i--;
                }else{
                    i++;
                    break;
                }
            }
            if (i == -1){
                i = 0;
            }
            while (i != 15){
                tmp = index(i, column)->getLetter();
                if (!tmp.empty()){
                    word.append(tmp);
                    i++;
                }else{
                    break;
                }
            }
            if (wordList->searchWord(word)){
                wordList->addWord(word);
            }
            word = "";
        }if (horizontal){
            while (j != -1){
                if (!index(row, j)->getLetter().empty()){
                    j--;
                }else{
                    j++;
                    break;
                }
            }
            if (j == -1){
                j = 0;
            }
            while (j != 15){
                tmp = index(row, j)->getLetter();
                if (!tmp.empty()){
                    word.append(tmp);
                    j++;
                }else{
                    break;
                }
            }
            if (wordList->searchWord(word)){
                wordList->addWord(word);
            }
        }
    }
}
