#include <iostream>
#include <string.h>

#define RED 0
#define BLACK 1
#define DOUBLE_BLACK 2

using namespace std;

class Nodo
{
   private:
      int valueMin;
      int valueMax;

      Nodo* right;
      Nodo* left;
      Nodo* parent;

      int color;

      bool nilNode;
   public:
      /**
       * @brief Nodo constructor for nilNode
       * 
       */
      Nodo();

      /**
       * @brief Nodo constructor for create single value Node. minValue and maxValue will have the same value
       * 
       * @param value
       */
      Nodo(int value);

      /**
       * @brief Nodo constructor for real RBTree Node
       * 
       * @param minValue 
       * @param maxValue 
       */
      Nodo(int minValue, int maxValue);

      /**
         * @brief 
         * 
         * @param value 
         * @return true
         * if value overlap the interval defined by valueMin and valueMax
         */
      bool checkOverlap(int value);

      /**
         * @brief 
         * 
         * @param x 
         * @param y
         * 
         * Methods that swap x and y values 
         */
      static void swapValues(Nodo* x, Nodo* y);
      
      //Getter
      int getValueMin();
      int getValueMax();
      Nodo* getRight();
      Nodo* getLeft();
      Nodo* getParent();
      int getColor();
      bool checkNil();

      //Setter
      void setValueMin(int newValue);
      void setValueMax(int newValue);
      void setRight(Nodo* newRight);
      void setLeft(Nodo* newLeft);
      void setParent(Nodo* newParent);
      void setColor(int newColor);
}; 