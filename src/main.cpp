#include "BTree.h"
#include <iostream>

using namespace std;

int main(){
    BTree testTree;
    testTree.insert(10);
    testTree.insert(8);
    testTree.insert(9);
    testTree.insert(6);
    testTree.insert(12);
    testTree.insert(11);
    testTree.insert(13);

    testTree.printTreePre();
    cout << endl;

    testTree.printTreePost();
    cout << endl;

    testTree.printTreeIn();
    cout << endl;

    cout << testTree.max() << endl;

    cout << testTree.min() << endl;

    cout << testTree.numNodes() << endl;

    cout << testTree.numLeafs() << endl;


    return 0;
}
