//
// Created by chus on 24/03/19.
//

#include "Btree.h"
#include <iostream>

using namespace std;


Btree::Btree(){
    root = NULL;
}

Btree::~Btree(){
    destroy_tree();
}

void Btree::destroy_tree(node *leaf){
    if(leaf != NULL){
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void Btree::insert(int key, node *leaf){

    if(key < leaf->value){
        if(leaf->left != NULL){
            insert(key, leaf->left);
        }else{
            leaf->left = new node;
            leaf->left->value = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }else if(key >= leaf->value){
        if(leaf->right != NULL){
            insert(key, leaf->right);
        }else{
            leaf->right = new node;
            leaf->right->value = key;
            leaf->right->right = NULL;
            leaf->right->left = NULL;
        }
    }

}

void Btree::insert(int key){
    if(root != NULL){
        insert(key, root);
    }else{
        root = new node;
        root->value = key;
        root->left = NULL;
        root->right = NULL;
    }
}

node *Btree::search(int key, node *leaf){
    if(leaf != NULL){
        if(key == leaf->value){
            return leaf;
        }
        if(key < leaf->value){
            return search(key, leaf->left);
        }else{
            return search(key, leaf->right);
        }
    }else{
        return NULL;
    }
}

node *Btree::search(int key){
    return search(key, root);
}

void Btree::destroy_tree(){
    destroy_tree(root);
}

void Btree::inorder_print(){
    inorder_print(root);
    cout << "\n";
}

void Btree::inorder_print(node *leaf){
    if(leaf != NULL){
        inorder_print(leaf->left);
        cout << leaf->value << ",";
        inorder_print(leaf->right);
    }
}

void Btree::postorder_print(){
    postorder_print(root);
    cout << "\n";
}

void Btree::postorder_print(node *leaf){
    if(leaf != NULL){
        inorder_print(leaf->left);
        inorder_print(leaf->right);
        cout << leaf->value << ",";
    }
}

void Btree::preorder_print(){
    preorder_print(root);
    cout << "\n";
}

void Btree::preorder_print(node *leaf){
    if(leaf != NULL){
        cout << leaf->value << ",";
        inorder_print(leaf->left);
        inorder_print(leaf->right);
    }
}
