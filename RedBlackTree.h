#include <iostream>
#include <stdlib.h>
#include "nodo.h"

#define RED 0
#define BLACK 1
#define DOUBLE_BLACK 2

class RedBlackTree{
    Nodo* root;

    public:
        /**
         * @brief Construct a new Red Black Tree object. Set root with a new nilNode 
         */
        RedBlackTree();

        /**
         * @brief Get the Root object
         */
        Nodo* getRoot();

        /**
         * @brief implement RBTrees left rotation
         */
        void leftRotate(Nodo* x);

        /**
         * @brief implement RBTrees right rotation
         */
        void rightRotate(Nodo* x);

        /**
         * @brief swap input pointers values. 
         * Doesn't affect object values but only pointers values
         */
        void swapNodes(Nodo** x, Nodo** y);

        /**
         * @brief Get the nodo uncle object. 
         * 
         * @param nodo 
         * @return Nodo* if nodo have an uncle in the tree 
         * @return nilNode if nodo doesn't have an uncle
         */
        Nodo* getUncle(Nodo* nodo);

        /**
         * @brief 
         * check if nodo is a left or right parent child
         * @param nodo
         * @return 0 if nodo is a left child
         * \n 1 if nodo is a right child
         * \n -1 if nodo doesn't have a parent 
         */
        int checkParentChild(Nodo* nodo);

        /**
         * @brief Get the Successor in RBTree
         * 
         * @param nodo 
         * @return Successor object if nodo have a successor
         * @return nilNode if nodo doesn't have a successor
         */
        Nodo* getSuccessor(Nodo* nodo);

        /**
         * @brief search object with value that equals to input value
         * 
         * @param value 
         * @return Nodo* if there is an object that have value equals to input value
         * \n nilNode if there isn't an object that have value equals to input value
         */
        Nodo* ricerca(int value);

        /**
         * @brief show the subtrees structure and values starting by a node
         * 
         * @param nodoAttuale is the start node
         */
        void preOrder(Nodo* nodoAttuale);

        /**
         * @brief Insert a node in RBTree. The new nodes have ever red color. 
         * It call insertFixUp to fix the tree to respect RBTree properties after the insert
         * 
         * @param value 
         */
        void insert(Nodo* newNodo);

        /**
         * @brief Starting by a node fix the tree to respect RBTree properties
         * If nodo is red and is parent is red too, try to fix the property with rotations and manipulations on tree 
         * 
         * @param nodo 
         */
        void insertFixUp(Nodo* nodo);

        /**
         * @brief Delete a node in RBTree. Can break RBTree properties introducing double black nodes in the tree
         * It call deleteFixUp to fix the tree to respect RBTree properties after delete 
         * 
         * @param nodo 
         */
        void elimina(Nodo* nodo);

        /**
         * @brief Starting by a node fix the tree to respect RBTree properties.
         * If nodo is a double black try to set the color to BLACK with rotations and manipulations on tree, to restore RBTree properties
         * 
         * @param nodo 
         */
        void deleteFixUp(Nodo* nodo);
};