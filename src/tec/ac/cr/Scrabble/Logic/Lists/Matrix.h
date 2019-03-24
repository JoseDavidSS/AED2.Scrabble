//
// Created by Alejandro Ibarra on 2019-03-23.
//

#ifndef SCRABBLE_MATRIX_H
#define SCRABBLE_MATRIX_H

#include <iostream>
#include "Node.h"
#include "List.h"
#include <sstream>
#include <string>

class MatrixNode {

public:
    MatrixNode *next;
    MatrixNode *prev;
    List list;
};

class Matrix {

private:
    MatrixNode *head,*tail;
    int length, rows, columns;

    /**
     * Builds list to display as a single string.
     * @param head Node pointer to start the display
     * @param result string to append values recursively
     */
    void display_aux(MatrixNode *node) {
        if (node == NULL) {

        } else {
            node->list.display();
            display_aux(node->next);
        }
    }

    MatrixNode * getHead() {
        return head;
    }

public:
    Matrix(int rows, int columns) {
        head = NULL;
        tail = NULL;
        length = 0;
    }

    /**
    * Add a new value to list.
    * @param n int to add
    * @param multiplier int specific multiplier of square. Default is 0 (no multiplier)
    */
    void addRow(List list) {
        MatrixNode *tmp = new MatrixNode;
        tmp->list = list;
        tmp->next = NULL;
        tmp->prev = tail;

        length += 1;

        if(head == NULL) {
            head = tmp;
            tail = tmp;
        }
        else {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    /**
    * Deletes a node from list.
    * @param letter string to add to position
    * @param i int of row
    * @param j int of column
    */
    void addIndex(string letter, int i, int j) {
        Node* pos = index(i, j);
        pos->letter = letter;
    }

    /**
    * Deletes a node from list.
    * @param toDel Node to delete
    */
    void del (MatrixNode *toDel) {
        if (toDel == head) {
            MatrixNode *temp;
            temp = head;
            head = head->next;
        } else {
            toDel->prev->next = toDel->next;
        }
        length -=1;
    }

    /**
     * Displays list as string.
     */
    void display() {
        display_aux(this->head);
    }

    /**
    * Gets Singleton instance of Matrix. Default is 15x15 board.
    * @return Matrix instance
    */
    static Matrix& getInstance(){
        static Matrix theInstance(15, 15);
        return theInstance;
    }

    /**
    * Finds the node with a specific index.
    * @param i row
    * @param j column
    * @return *Node
    */
    Node* index(int i, int j) {
        MatrixNode *tmp = head;
        int counter = 1;
        while (counter != i) {
            tmp = tmp->next;
            counter++;
        }
        Node* result = tmp->list.index(j);
        return result;
    }

};


#endif //SCRABBLE_MATRIX_H
