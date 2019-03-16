//
// Created by chus on 16/03/19.
//

#include <cstdio>
#include <iostream>
#include "List.h"

using namespace std;

int List::getLenght(){
    return this->lenght;
}

void List::setLenght(int lenght) {
    this->lenght = lenght;
}

void List::insertNode(string letter, int points, int counter){
    if (this->head == nullptr){
        this->head = new Node(letter, points, counter);
        this->lenght++;
    }else{
        Node* tmp = this->head;
        while (tmp->next != nullptr){
            tmp = tmp->next;
        }
        tmp->next = new Node(letter, points, counter);
        this->lenght++;
    }
}

void List::deleteNode(string letter){
    if (this->head == nullptr){
        printf("Theres no node to delete");
    }else if(this->head->getLetter() == letter){
        this->head = this->head->next;
        this->lenght--;
    }else{
        Node* tmp = this->head;
        while (tmp->next != nullptr){
            if (tmp->next->getLetter() == letter){
                tmp->next = tmp->next->next;
                this->lenght--;
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