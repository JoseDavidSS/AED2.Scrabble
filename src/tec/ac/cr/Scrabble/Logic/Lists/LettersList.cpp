//
// Created by chus on 16/03/19.
//

#include <cstdio>
#include <iostream>
#include "LettersList.h"

using namespace std;

void List::letterSorter(){
    insertNode("A", 1, 12);
    insertNode("E", 1, 12);
    insertNode("0", 1, 9);
    insertNode("I", 1, 6);
    insertNode("S", 1, 6);
    insertNode("N", 1, 5);
    insertNode("L", 1, 4);
    insertNode("R", 1, 5);
    insertNode("U", 1, 5);
    insertNode("T", 1, 4);
    insertNode("D", 2, 5);
    insertNode("G", 2, 2);
    insertNode("C", 3, 4);
    insertNode("B", 3, 2);
    insertNode("M", 3, 2);
    insertNode("P", 3, 2);
    insertNode("H", 4, 2);
    insertNode("F", 4, 1);
    insertNode("V", 4, 1);
    insertNode("Y", 4, 1);
    insertNode("Ch", 5, 1);
    insertNode("Q", 5, 1);
    insertNode("J", 8, 1);
    insertNode("Ll", 8, 1);
    insertNode("Ñ", 8, 1);
    insertNode("RR", 8, 1);
    insertNode("X", 8, 1);
    insertNode("Z", 10, 1);
    insertNode("", 0, 2);
}

int List::getLenght(){
    return this->length;
}

void List::setLenght(int lenght) {
    this->length = lenght;
}

void List::insertNode(string letter, int points, int counter){
    if (this->head == nullptr){
        this->head = new Node(letter, points, counter);
        this->length++;
    }else{
        Node* tmp = this->head;
        while (tmp->next != nullptr){
            tmp = tmp->next;
        }
        tmp->next = new Node(letter, points, counter);
        this->length++;
    }
}

void List::deleteNode(string letter){
    if (this->head == nullptr){
        printf("Theres no node to delete");
    }else if(this->head->getLetter() == letter){
        this->head = this->head->next;
        this->length--;
    }else{
        Node* tmp = this->head;
        while (tmp->next != nullptr){
            if (tmp->next->getLetter() == letter){
                tmp->next = tmp->next->next;
                this->length--;
                break;
            }else{
                tmp = tmp->next;
            }
        }
    }
}

void List::printList (){
    if (this->head == nullptr){
        printf("Lista nula");
    }else{
        Node* tmp = this->head;
        while (tmp != nullptr){
            cout << tmp->getLetter() << endl;
            tmp = tmp->next;
        }
    }
}