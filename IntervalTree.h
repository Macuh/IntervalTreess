#include "RedBlackTree.h"

class IntervalTree : public RedBlackTree{
    public: 
        IntervalTree() : RedBlackTree(){

        }
        
        Nodo* ricerca(int value);
};