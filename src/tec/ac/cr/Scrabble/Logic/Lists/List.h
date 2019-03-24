//
// Created by Alejandro Ibarra on 2019-03-23.
//

#ifndef SCRABBLE_LIST_H
#define SCRABBLE_LIST_H


#include "Node.h"
#include <iostream>

using namespace std;

class List {

private:
    Node *head,*tail;
    int length;

    /**
     * Deletes a node from list.
     * @param toDel
     */
    void del (Node *toDel) {
        if (toDel == head) {
            Node *temp;
            temp = head;
            head = head->next;
            delete temp;
        } else {
            toDel->prev->next = toDel->next;
            delete toDel;
        }
        length -= 1;
    }

    /**
     * Builds list to display as a single string.
     * @param head
     * @param result
     */
    void display_aux(Node *head, string result) {
        if(head == NULL) {
            result.erase(result.size() - 2);
            result.append("]");
            cout << result << endl;
        }
        else {
            string current = to_string(head->data);
            result.append(current);
            result.append(", ");
            display_aux(head->next, result);
        }
    }

public:
    List() {
        head = NULL;
        tail = NULL;
        length = 0;
    }
    /**
     * Add a new value to list.
     * @param n
     */
    void add(int n) {
        Node *tmp = new Node;
        tmp->data = n;
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
     * Displays list as a string.
     */
    void display() {
        display_aux(gethead(), "[");
    }

    /**
     * Gets head node of list.
     * @return
     */
    Node* gethead() {
        return head;
    }

    /**
     * Get list length.
     * @return
     */
    int getLength() const {
        return length;
    }

    /**
     * Remove a specific value from list.
     * @param int n
     */
    void remove(int n) {
        Node *temp = this->head;
        while (temp != NULL) {
            if (temp->data == n) {
                del(temp);
            }
            temp = temp->next;
        }
    }

};


#endif //SCRABBLE_LIST_H
