#include "BTree.h"

BTree::BTree(){
    root = NULL;
}

BTree::~BTree(){
    deleteTree();
}

/**
*   this method allows the user to delete the entire tree it calls the deleteTree(Node*) method that
*   will recursively delete all the nodes in the tree
*/
void BTree::deleteTree(){
    deleteTree(root);
}

/**
*   this method recursively deletes all the nodes in the tree starting with the leaf nodes
*   @param _leaf the node to delete
*/
void BTree::deleteTree(Node _leaf){
    if (leaf != null){
        deleteTree(_leaf->left);
        deleteTree(_leaf->right);
        delete _leaf;
    }
}

/**
*   This method allows the user to insert a value that will create a new node
*   The tree is traversed recursively and the new node is inserted in the appropriate place
*   @param _value int the value that will be inserted into the tree
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
*   @param _value int the value that will be inserted into the tree
*   @param _node the node to be checked against _value
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



/**
*   This method calls a method that traverses the tree in pre-order
*   @return string containing the nodes of the tree in pre-order
*/
string BTree::printTreePre(){
    string result = "";
    return printTreePre(root);
}

/**
*   This method traverses the tree in pre-order and returns the values as a string
*   @return string containing the nodes of the tree in pre-order
*/
string BTree::printTreePre(Node* _root, string _result){
    if (_root != NULL){
        _result += _root->value + " ";
        printTreePre(_root->left, _result);
        printTreePre(_root->right, _result);
    }
    return _result;
}



/**
*   This method calls a method that traverses the tree in post-order
*   @return string containing the nodes of the tree in post-order
*/
string BTree::printTreePost(){
    string result = "";
    return printTreePost(root, result);
}

/**
*   This method traverses the tree in post-order and returns the values as a string
*   @return string containing the nodes of the tree in post-order
*/
string BTree::printTreePost(Node* _root, string _result){
    if (_root != NULL){
        printTreePost(_root->left, _result);
        printTreePost(_root->right, _result);
        _result += _root->value + " ";
    }
    return _result;
}

/**
*   This method calls a method that traverses the tree in in-order
*   @return string containing the nodes of the tree in in-order
*/
string BTree::printTreeIn(){
    string result = "";
    return printTreeIn(root, result);
}

/**
*   This method traverses the tree in in-order and returns the values as a string
*   @return string containing the nodes of the tree in in-order
*/
string BTree::printTreeIn(Node* _root, string _result){
    if (_root != NULL){
        printTreeIn(_root->left, _result);
        _result += _root->value + " ";
        printTreeIn(_root->right, _result);

    }
    return _result;
}


int BTree::max(){
    if (root != NULL){
        if (root->right != NULL){
            return max(root->right);
        } else {
            return root->value;
        }
    } else {
        return 0;
    }
}

int BTree::max(Node* _root){
    if (_root->right != NULL){
        max(_root->right);
    } else {
        return _root->value;
    }
}

int BTree::min(){
    if (root != NULL){
        if (root->left != NULL){
            return min(root->left);
        } else {
            return root->value;
        }

    } else {
        return 0;
    }
}

int BTree::min(Node* _root){
    if (_root->left != NULL){
        min(_root->left);
    } else {
        return _root->left;
    }
}


int BTree::height();
int BTree::numNodes();
int BTree::numLeafs();




