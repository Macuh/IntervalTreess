#include "RedBlackTree.h"

class IntervalTree : public RedBlackTree{
    public: 
        IntervalTree() : RedBlackTree(){

        }
        /**
         * @brief Search a interval that overlap the interval defined by valueMin and valueMax params
         * 
         * @param value 
         * @return Nodo* if exists a interval that overlap interval defined by valueMin and valueMax params, otherwise return a nilNode
         */
        Nodo* ricerca(int valueMin, int valueMax);

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