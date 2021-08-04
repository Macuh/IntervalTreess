#include "RedBlackTree.h"

class IntervalTree : public RedBlackTree{
    public: 
        IntervalTree() : RedBlackTree(){

        }
        /**
         * @brief Search a interval that overlap the param value
         * 
         * @param value 
         * @return Nodo* if exists a interval that overlap value, otherwise return a nilNode
         */
        Nodo* ricerca(int value);

        /**
         * @brief Call the RedBlackTree::insert method but, after that, update the maxSubtree values of the nodes
         * 
         * @param newNodo 
         */
        void insert(Nodo* newNodo);

        /**
         * @brief Call the RedBlackTree::elimina method but, after that, update the maxSubtree valures of the nodes
         * 
         * @param nodo 
         */
        void elimina(Nodo* nodo);

        /**
         * @brief Update maxSubtree values of the nodes with a postOrder tree visit
         * 
         * @param newNodo 
         * @return the max interval up bound contained in the tree
         */
        int updateMaxSubtree(Nodo* newNodo);
};