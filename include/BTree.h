#ifndef BTREE_H
#define BTREE_H

/**
*   Node: Contains a value and two children (left child and right child).
*/
struct Node {
    int value;
    node* left;
    node* right;

    // constructor sets value to 0 if no parameter is given
    Node(int _value) : value(0){
        value = _value;
        left = NULL;
        right = NULL;
    }
};

class BTree{
    public:
        BTree();
        ~BTree();

        void insert(int _value);
        void deleteTree();

        Node* search(int _value);

        int find(node* _node);
        int height();
        int numNodes();
        int numLeafs();

    private:
        Node* root;

        void deleteNode(Node* _leaf);
        void insert(Node* _node);

        Node* search(int _value, Node* node);

        int find(node* _node);
        int countNodes(Node* root);
        int countLeafs(Node* root);
};

#endif // BTREE_H
