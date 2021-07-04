#include "RedBlackTree.h"

class IntervalTree : public RedBlackTree{
    public: 
        IntervalTree() : RedBlackTree(){

        }

        void insert(int minValue, int maxValue);
        Nodo* ricerca(int value);
};