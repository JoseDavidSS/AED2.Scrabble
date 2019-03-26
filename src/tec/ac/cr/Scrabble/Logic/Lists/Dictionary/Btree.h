//
// Created by chus on 24/03/19.
//

#ifndef SCRABBLE_BTREE_H
#define SCRABBLE_BTREE_H


#include <iostream>

using namespace std;


struct node{
    int value;
    node *left;
    node *right;
};

class Btree{
public:
    Btree();
    ~Btree();

    void insert(int key);
    node *search(int key);
    void destroy_tree();
    void inorder_print();
    void postorder_print();
    void preorder_print();

public:
    void destroy_tree(node *leaf);
    void insert(int key, node *leaf);
    node *search(int key, node *leaf);
    void inorder_print(node *leaf);
    void postorder_print(node *leaf);
    void preorder_print(node *leaf);

    node *root;
};
#endif //SCRABBLE_BTREE_H
