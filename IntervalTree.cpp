#include "IntervalTree.h"

Nodo* IntervalTree::ricerca(int value){
    Nodo* app = getRoot();

    while(!(app->checkNil()) && !(app->checkOverlap(value))){
        if(!(app->getLeft()->checkNil()) && app->getLeft()->getValueMax() >= value)
            app = app->getLeft();
        else 
            app = app->getRight();
    }

    return app;
}