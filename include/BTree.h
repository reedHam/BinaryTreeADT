#ifndef BTREE_H
#define BTREE_H

/**
*   Node: Contains a value and two children.
*/
struct node {
    int value;
    node* left;
    node* right;

    // constructor
    node(){
        value = -1; // Set to -1 for the calculation of tree height.
        left = NULL;
        right = NULL;
    }
};

class BTree{
    public:
        /** Default constructor */
        BTree();
        /** Default destructor */
        ~BTree();

    protected:

    private:
};

#endif // BTREE_H
