#include <iostream>
#include <stdlib.h>

#define RED 0
#define BLACK 1
#define DOUBLE_BLACK 2

class Nodo{
    private:
        int valueMin;
        int valueMax;

        Nodo* right;
        Nodo* left;
        Nodo* parent;

        int color;

        bool nilNode;
    
    public:
        //Nodo constructor for real RBTree Node
        Nodo(int valueMin, int valueMax){
            this->valueMin = valueMin;
            this->valueMax = valueMax;

            right = new Nodo();
            left = new Nodo();
            parent = new Nodo();

            color = RED;
            nilNode = false;
        }

        //Nodo constructor for nilNode
        Nodo(){
            right = this;
            left = this;
            parent = this;
            
            color = BLACK;

            nilNode = true;
        }

        /**
         * @brief 
         * 
         * @param value 
         * @return true
         * if value overlap the interval defined by valueMin and valueMax
         */
        bool checkOverlap(int value){
            if(value >= valueMin && value <= valueMax)
                return true;
            else 
                return false;
        }

        /**
         * @brief 
         * 
         * @param x 
         * @param y
         * 
         * Methods that swap x and y values 
         */
        static void swapValues(Nodo* x, Nodo* y){
            int minApp = y->valueMin;
            int maxApp = y->valueMax;

            y->valueMin = x->valueMin;
            y->valueMax = x->valueMax;

            x->valueMin = minApp;
            x->valueMax = maxApp;
        }

        //Getter

        int getValueMin(){
            return valueMin;
        }

        int getValueMax(){
            return valueMax;
        }

        Nodo* getRight(){
            return right;
        }

        Nodo* getLeft(){
            return left;
        }

        Nodo* getParent(){
            return parent;
        }

        int getColor(){
            return color;
        }

        bool checkNil(){
            return nilNode;
        }

        //Setter

        void setValueMin(int newValue){
            valueMin = newValue;
        }

        void setValueMax(int newValue){
            valueMax = newValue;
        }

        void setRight(Nodo* newRight){
            right = newRight;
        }

        void setLeft(Nodo* newLeft){
            left = newLeft;
        }

        void setParent(Nodo* newParent){
            parent = newParent;
        }

        void setColor(int newColor){
            color = newColor;
        }
};