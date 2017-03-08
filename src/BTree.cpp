#include "BTree.h"

BTree::BTree(){
    root = NULL;
}

BTree::~BTree(){
    deleteTree();
}

/**
*   this method allows the user to delete the tree it calls the deleteNode method that
*   will recursively delete all the nodes in the tree
*/
void BTree::deleteTree(){
    deleteNode(root);
}

/**
*   this method allows the user to delete the tree it calls the delete node function that
*   will recursively delete all the nodes in the tree
*/
void BTree::deleteNode(Node _leaf){
}

/**
*   This method allows the user to insert a value that will create a new node
*   The tree is traversed recursively and the new node is inserted in the appropriate place
*   @pram _value int the value that will be inserted into the tree
*/
void BTree::insert(int _value){
    if (root != NULL){
        insert(_value, root);
    } else { // if root is null then insert at top of tree
        root = new Node(_value);
    }
}

/**
*   This method traverses the tree and inserts the value as a new node in the
*   correct position
*   will not insert duplicate values
*   @pram _value int the value that will be inserted into the tree
*   @pram _node the node to be checked against _value
*/
void BTree::insert(int _value, Node* _node){
    if (_value < _node->value){
        if (_node->left != NULL){ // if there is a left child recurse
            insert(_value, _node->left);
        } else { // if there is no left child insert node here
            _node->left = new Node(_value);
        }
    } else if (_value > _node->value){
        if (_node->right != NULL){ // if there is a right child recurse
            insert(_value, _node->right);
        } else { // if there is no right child insert node here
            _node->right = new Node(_value);
        }
    } else { // if the value is a duplicate then return
        return;
    }
}

