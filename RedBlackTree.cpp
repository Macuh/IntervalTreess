#include "RedBlackTree.h"

RedBlackTree::RedBlackTree(){
    root = new Nodo();
}

Nodo* RedBlackTree::getRoot(){
    return root;
}

void RedBlackTree::leftRotate(Nodo* x){
    Nodo* nodo = x->getRight();
    if(nodo->checkNil()) return;

    if(x == root)
        root = nodo;
 
    if(!(x->getParent()->checkNil()) && checkParentChild(x) == 1)
        x->getParent()->setLeft(nodo);
    if(!(x->getParent()->checkNil()) && checkParentChild(nodo) == 0)
        x->getParent()->setRight(nodo);

    nodo->setParent(x->getParent());
    x->setParent(nodo);

    x->setRight(nodo->getLeft());
    nodo->getLeft()->setParent(x);
    nodo->setLeft(x);
}

void RedBlackTree::rightRotate(Nodo* x){
    Nodo* nodo = x->getLeft();
    if(nodo->checkNil()) return;

    if(x == root)
        root = nodo;
 
    if(!(x->getParent()->checkNil()) && checkParentChild(x) == 1)
        x->getParent()->setLeft(nodo);
    if(!(x->getParent()->checkNil()) && checkParentChild(nodo) == 0)
        x->getParent()->setRight(nodo);

    nodo->setParent(x->getParent());
    x->setParent(nodo);

    x->setLeft(nodo->getRight());
    nodo->getRight()->setParent(x);
    nodo->setRight(x);
}

void RedBlackTree::swapNodes(Nodo** x, Nodo** y){
    Nodo* app = *x;
    *x = *y;
    *y = app;
}

Nodo* RedBlackTree::getUncle(Nodo* nodo){
    if(!(nodo->getParent()->checkNil()) && !(nodo->getParent()->getParent()->checkNil())){
        if(checkParentChild(nodo->getParent()) == 0)
            return nodo->getParent()->getParent()->getRight();
        else if(checkParentChild(nodo->getParent()) == 1)
            return nodo->getParent()->getParent()->getLeft();
    }

    return new Nodo();
}

int RedBlackTree::checkParentChild(Nodo* nodo){
    if(nodo->getParent()->getLeft() == nodo) return 0;
    else if(nodo->getParent()->getRight() == nodo) return 1;
    else return -1;
}

Nodo* RedBlackTree::getSuccessor(Nodo* nodo){
    Nodo* app = nodo->getRight();

    while(!(app->getLeft()->checkNil())){
        app = app->getLeft();
    }

    return app;
}

Nodo* RedBlackTree::ricerca(int value){
    Nodo* app = root;

    while(!app->checkNil()){
        if(app->getValueMin() == value) return app;

        if(app->getValueMin() > value) app = app->getLeft();
        else app = app->getRight();
    }

    return app;
}

void RedBlackTree::inOrder(Nodo* nodoAttuale){
    if(!(nodoAttuale->getLeft()->checkNil())) inOrder(nodoAttuale->getLeft());
    cout << nodoAttuale->getValueMin() << " " << nodoAttuale << " " << nodoAttuale->getLeft() << " " << nodoAttuale->getRight() << " " << nodoAttuale->getColor() << endl;
    if(!(nodoAttuale->getRight()->checkNil())) inOrder(nodoAttuale->getRight());
}

void RedBlackTree::insert(Nodo* newNodo){
    Nodo* nodoAttuale = root;
    Nodo* nodoPrec = root;

    while(!(nodoAttuale->checkNil())){
        nodoPrec = nodoAttuale;

        if(newNodo->getValueMin() <= nodoAttuale->getValueMin())
            nodoAttuale = nodoAttuale->getLeft();
        else
            nodoAttuale = nodoAttuale->getRight();
    }

    newNodo->setParent(nodoPrec);

    if(nodoPrec->checkNil()){
        root = newNodo;
        newNodo->setColor(BLACK);
    }
    else if(newNodo->getValueMin() <= nodoPrec->getValueMin())
        nodoPrec->setLeft(newNodo);
    else
        nodoPrec->setRight(newNodo);

    insertFixUp(newNodo);
}

void RedBlackTree::insertFixUp(Nodo* nodo){
    Nodo* nodoPadre = nodo->getParent();

    if(!(nodoPadre->checkNil()) && nodoPadre->getColor() == RED){
        //Case 1
        if(getUncle(nodo)->getColor() == RED){
            getUncle(nodo)->setColor(BLACK);
            nodoPadre->setColor(BLACK);
            nodoPadre->getParent()->setColor(RED);

            if(nodoPadre->getParent() == root)
                nodoPadre->getParent()->setColor(BLACK);
            else  
                insertFixUp(nodoPadre->getParent());
        }
        else{
            if(!(nodoPadre->getParent()->checkNil())){
                nodoPadre->getParent()->setColor(RED);

                //Case 2
                if(nodoPadre == nodoPadre->getParent()->getLeft()){
                    if(nodoPadre->getRight() == nodo){
                        leftRotate(nodoPadre);
                        swap(nodoPadre, nodo);
                    }

                    rightRotate(nodoPadre->getParent());  
                }
                //Case 3
                else{
                    if(nodoPadre->getLeft() == nodo){
                        rightRotate(nodoPadre);
                        swap(nodoPadre, nodo);
                    }

                    leftRotate(nodoPadre->getParent());
                }

                nodoPadre->setColor(BLACK);
            }
        }
    }
}

void RedBlackTree::elimina(Nodo* nodo){
    Nodo* childNotNull;
    if(nodo->checkNil()) return;

    if(!(nodo->getLeft()->checkNil()) && !(nodo->getRight()->checkNil())){
        Nodo* min = getSuccessor(nodo);

        Nodo::swapValues(nodo, min);
        elimina(min);
        return;
    }
    else{
        if(!(nodo->getLeft()->checkNil())) 
            childNotNull = nodo->getLeft();
        else
            childNotNull = nodo->getRight();
    }
    
    if(childNotNull->getColor() == RED)
        childNotNull->setColor(BLACK);
    else if(nodo->getColor() == BLACK){
        childNotNull->setColor(DOUBLE_BLACK);
    }
        
    childNotNull->setParent(nodo->getParent());

    if(nodo->getParent()->getLeft() == nodo)
        nodo->getParent()->setLeft(childNotNull);
    if(nodo->getParent()->getRight() == nodo)   
        nodo->getParent()->setRight(childNotNull);

    delete nodo;
    if(childNotNull->getParent()->checkNil()) root = childNotNull;
    deleteFixUp(childNotNull);
}

void RedBlackTree::deleteFixUp(Nodo* nodo){
    Nodo* brother;

    if(nodo->getColor() != DOUBLE_BLACK) return;

    if(nodo->getParent()->checkNil()){
        nodo->setColor(BLACK);
        return;
    }
    else
        if(checkParentChild(nodo) == 1)
            brother = nodo->getParent()->getLeft();
        else
            brother = nodo->getParent()->getRight();
    
    if(brother->getColor() == RED){
        if(checkParentChild(nodo) == 0)
            leftRotate(nodo->getParent());
        else
            rightRotate(nodo->getParent());
        
        brother->setColor(BLACK);
        nodo->getParent()->setColor(RED);
        deleteFixUp(nodo);
    }
    else{
        if(brother->checkNil() || (brother->getLeft()->getColor() == BLACK && brother->getRight()->getColor() == BLACK)){
            nodo->setColor(nodo->getColor() - 1);
            if(!(brother->checkNil())) brother->setColor(brother->getColor() - 1);
            nodo->getParent()->setColor(nodo->getParent()->getColor() + 1);

            if(nodo->getParent()->getColor() == DOUBLE_BLACK) deleteFixUp(nodo->getParent());
        }
        else{
            if(checkParentChild(nodo) == 0 && brother->getLeft()->getColor() == RED && brother->getRight()->getColor() == BLACK){
                rightRotate(brother);
                deleteFixUp(nodo);
            }
            if(checkParentChild(nodo) == 1 && brother->getRight()->getColor() == RED && brother->getLeft()->getColor() == BLACK){
                leftRotate(brother);
                deleteFixUp(nodo);
            }

            if(checkParentChild(nodo) == 0){
                brother->getRight()->setColor(BLACK);
                leftRotate(nodo->getParent());
            }
            else{
                brother->getLeft()->setColor(BLACK);
                rightRotate(nodo->getParent());
            }

            nodo->getParent()->setColor(BLACK);
            nodo->setColor(BLACK);   
        }
    }
}