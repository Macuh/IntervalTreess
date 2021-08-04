#include "RedBlackTree.h"

class IntervalTree : public RedBlackTree{
    public: 
        IntervalTree() : RedBlackTree(){

        }
        
        Nodo* ricerca(int value);
        void intervalInsert(Nodo* newNodo);
        int updateMaxSubtree(Nodo* newNodo);
};