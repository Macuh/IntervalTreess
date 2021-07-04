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