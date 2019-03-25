//
// Created by Alejandro Ibarra on 2019-03-23.
//

#include "Matrix.h"
#include <unordered_set>

Matrix* Matrix::matrix = nullptr;

/**
* Gets Singleton instance of Matrix. Default is 15x15 board.
* @return Matrix instance
*/
Matrix* Matrix::getInstance() {
    if (!matrix) {
        matrix = new Matrix();
        matrix->initialize();
        matrix->assignMultipliers();
    }
    return matrix;
}

/**
* Add a new value to list.
* @param n int to add
* @param multiplier int specific multiplier of square. Default is 0 (no multiplier)
*/
void Matrix::addRow(List* list) {
    if (this->head == nullptr) {
        this->head = list;
    } else {
        List* tmp = this->head;
        while (tmp->next != nullptr){
            tmp = tmp->next;
        }
        tmp->next = list;
    }
    this->length++;
}

/**
* Adds a specific value in position.
* @param letter string to add to position
* @param i int of row
* @param j int of column
*/
void Matrix::addIndex(string letter, int i, int j) {
    Node* pos = index(i, j);
    pos->letter = letter;
}


/**
* Assigns multipliers to nodes based on default Scrabble board.
*/
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
            if (DL.count(tmp->id)) {
                tmp->multiplier = 1;
            } else if (DW.count(tmp->id)) {
                tmp->multiplier = 2;
            } else if (TL.count(tmp->id)) {
                tmp->multiplier = 3;
            } else if (TW.count(tmp->id)) {
                tmp->multiplier = 4;
            }
            tmp = tmp->next;
        }
        currentList = currentList->next;
        if (currentList != nullptr) {
            tmp = currentList->getHead();
        }
    }
}

/**
 * Displays list as string.
 */
void Matrix::display() {
    List* tmp = this->head;
    while (tmp != nullptr) {
        tmp->display();
        tmp = tmp->next;
    }
}

/**
* Finds the node with a specific index.
* @param i row
* @param j column
* @return *Node
*/
Node* Matrix::index(int i, int j) {
    List* tmp = head;
    int counter = 1;
    while (counter != i) {
        tmp = tmp->next;
        counter++;
    }
    Node* result = tmp->index(j);
    return result;
}

/**
* Initializes empty 15x15 matrix with preset multipliers.
*/
void Matrix::initialize() {
    int rows = 15;
    int columns = 15;
    int columnsBackup = columns;
    int n = 1;

    while (rows != 0) {
        if (this->head == nullptr) {
            this->head = new List();
            while (columns != 0){
                this->head->add(to_string(n), n);
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
                tmp->next->add(to_string(n), n);
                n++;
                columns--;
            }
        }
        rows--;
        columns = columnsBackup;
        this->length++;
    }
}