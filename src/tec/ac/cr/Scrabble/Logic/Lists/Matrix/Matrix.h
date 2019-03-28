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

class Matrix {

public:

    Matrix(int rows, int columns) {
        head = nullptr;
        length = 0;
    }

    List* head = nullptr;

    int getLenght();
    void setLenght(int lenght);
    int getRows();
    void setRows(int rows);
    int getColumns();
    void setColumns(int columns);
    void addRow(List* list);
    void addIndex(string letter, int i, int j);
    void display();
    static Matrix* getInstance();
    Node* index(int i, int j);
    void initialize();

private:

    Matrix() = default;
    Matrix(Matrix const&)= default;
    Matrix& operator = (Matrix const&) = default;

    static Matrix* matrix;
    int length, rows, columns;

    void assignMultipliers();

};


#endif //SCRABBLE_MATRIX_H
