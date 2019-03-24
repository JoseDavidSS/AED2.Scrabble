//
// Created by Alejandro Ibarra on 2019-03-23.
//

#include "Matrix.h"

Matrix* Matrix::matrix = nullptr;

/**
* Gets Singleton instance of Matrix. Default is 15x15 board.
* @return Matrix instance
*/
Matrix* Matrix::getInstance() {
    if (!matrix) {
        matrix = new Matrix();
        matrix->initialize();
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

void Matrix::assignMultipliers() {
    Node* tmp = this->head->getHead();
    while (tmp != nullptr) {
        if (tmp->id == 1) {
            
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