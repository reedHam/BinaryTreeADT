#include "BTree.h"
#include <iostream>

using namespace std;

int main(){
    BTree testTree;
    for (int i = 1; i <= 10; i++){
        testTree.insert(i * 10);
    }

    testTree.printTreeIn();
    return 0;
}
