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
     * @param toDel Node to delete
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
     * @param head Node pointer to start the display
     * @param result string to append values recursively
     */
    void display_aux(Node *head, string result) {
        if(head == NULL) {
            result.erase(result.size() - 2);
            result.append("]");
            cout << result << endl;
        }
        else {
            string current = head->letter;
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
     * @param n int to add
     * @param multiplier int specific multiplier of square. Default is 0 (no multiplier)
     * 0 = NO, 1 = DL, 2 = DW, 3 = TL, 4 = TW.
     */
    void add(string n, int multiplier = 0) {
        Node *tmp = new Node;
        tmp->letter = n;
        tmp->next = NULL;
        tmp->prev = tail;

        // Adjusts multiplier type of node.
        if (multiplier == 0) {
            tmp->multiplier = 0;
        } else {
            tmp->multiplier= multiplier;
        }

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
        display_aux(getHead(), "[");
    }

    Node* getHead() {
        return head;
    }

    int getLength() const {
        return length;
    }

    /**
    * Finds the node with a specific index.
    * @param n position of value
    * @return *Node node in position n
    */
    Node* index(int n) {
        Node *tmp = head;
        int i = 1;
        while (i != n) {
            tmp = tmp->next;
            i++;
        }
        cout << tmp->letter << endl;
        return tmp;
    }

    /**
     * Remove a specific value from list.
     * @param n int value to remove
     */
    void remove(string n) {
        Node *temp = this->head;
        while (temp != NULL) {
            if (temp->letter == n) {
                del(temp);
            }
            temp = temp->next;
        }
    }

};


#endif //SCRABBLE_LIST_H
