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

int IntervalTree::updateMaxSubtree(Nodo* nodoAttuale){
    int maxLeft = 0;
    int maxRight = 0;

    if(!nodoAttuale->getLeft()->checkNil())
        maxLeft = updateMaxSubtree(nodoAttuale->getLeft());
    
    if(!nodoAttuale->getRight()->checkNil())
        maxRight = updateMaxSubtree(nodoAttuale->getRight());

    if(nodoAttuale->getValueMax() < maxLeft || nodoAttuale->getValueMax() < maxRight){
        if(maxLeft > maxRight)
            nodoAttuale->setMaxValueInSub(maxLeft);
        else   
            nodoAttuale->setMaxValueInSub(maxRight);
    }

    return nodoAttuale->getMaxValueInSub();
}

void IntervalTree::intervalInsert(Nodo* newNodo){
    this->insert(newNodo);
    updateMaxSubtree(this->getRoot());
}