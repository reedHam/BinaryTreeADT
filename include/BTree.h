#ifndef BTREE_H
#define BTREE_H

#include <string>

class BTree{
    public:
        BTree();
        ~BTree();

        void deleteTree();
        void insert(int _value);
        std::string printTreePre();
        std::string printTreePost();
        std::string printTreeIn();

        int max();
        int min();
        int height();
        int numNodes();
        int numLeafs();

    private:
        /**
        *   Node: Contains a value and two children (left child and right child).
        */
        struct Node {
            int value;
            Node* left;
            Node* right;
            bool visited;

            // constructor sets value to 0 if no parameter is given
            Node(int _value) : value(0){
                value = _value;
                left = NULL;
                right = NULL;
                visited = false;
            }
        };

        Node* root;

        void deleteTree(Node* _leaf);
        void insert(int _value, Node* _node);
        std::string printTreePre(Node* _root, std::string &_result);
        std::string printTreePost(Node* _root, std::string &_result);
        std::string printTreeIn(Node* _root, std::string &_result);

        int max(Node* _root);
        int min(Node* _root);
        int countNodes(Node* _root);
        int countLeafs(Node* _root);
};

#endif // BTREE_H
