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