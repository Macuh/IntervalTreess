#include <iostream>
#include <stdlib.h>

#include "IntervalTree.h"

int main(int argc, char const *argv[]){
    IntervalTree* intervalTree = new IntervalTree();
    intervalTree->insert(new Nodo(16, 21));
        cout << "--------------------" << endl;
        intervalTree->inOrder(intervalTree->getRoot());
    intervalTree->insert(new Nodo(8, 9));
        cout << "--------------------" << endl;
        intervalTree->inOrder(intervalTree->getRoot());
    intervalTree->insert(new Nodo(5, 8));
        cout << "--------------------" << endl;
        intervalTree->inOrder(intervalTree->getRoot());
    intervalTree->insert(new Nodo(0, 3));
        cout << "--------------------" << endl;
        intervalTree->inOrder(intervalTree->getRoot());
    intervalTree->insert(new Nodo(6, 10));
        cout << "--------------------" << endl;
        intervalTree->inOrder(intervalTree->getRoot());
    intervalTree->insert(new Nodo(15,23));
        cout << "--------------------" << endl;
        intervalTree->inOrder(intervalTree->getRoot());
    intervalTree->insert(new Nodo(25, 30));
        cout << "--------------------" << endl;
        intervalTree->inOrder(intervalTree->getRoot());
    intervalTree->insert(new Nodo(17, 19));
        cout << "--------------------" << endl;
        intervalTree->inOrder(intervalTree->getRoot());
    intervalTree->insert(new Nodo(19, 20));
        cout << "--------------------" << endl;
        intervalTree->inOrder(intervalTree->getRoot());
    intervalTree->insert(new Nodo(26, 26));
        cout << "--------------------" << endl;
        intervalTree->inOrder(intervalTree->getRoot());
    
    return 0;
}
