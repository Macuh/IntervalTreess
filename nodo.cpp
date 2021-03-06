#include <iostream>
#include <stdlib.h>
#include "nodo.h"

Nodo::Nodo(int value){
    this->valueMin = value;
    this->valueMax = value;

    this->maxValueInSub = 0;

    right = new Nodo();
    left = new Nodo();
    parent = new Nodo();

    color = RED;
    nilNode = false;
}

Nodo::Nodo(int valueMin, int valueMax){
    this->valueMin = valueMin;
    this->valueMax = valueMax;

    this->maxValueInSub = valueMax;

    right = new Nodo();
    left = new Nodo();
    parent = new Nodo();

    color = RED;
    nilNode = false;
}

Nodo::Nodo(){
    right = this;
    left = this;
    parent = this;
    
    color = BLACK;

    nilNode = true;
}

bool Nodo::checkOverlap(int valueMin, int valueMax){
    if(valueMax >= this->getValueMin() && valueMin <= this->getValueMax())
        return true;
    else  
        return false;
}

void Nodo::swapValues(Nodo* x, Nodo* y){
    int minApp = y->valueMin;
    int maxApp = y->valueMax;

    y->valueMin = x->valueMin;
    y->valueMax = x->valueMax;

    x->valueMin = minApp;
    x->valueMax = maxApp;
}

//Getter

int Nodo::getValueMin(){
    return valueMin;
}

int Nodo::getValueMax(){
    return valueMax;
}

int Nodo::getMaxValueInSub(){
    return maxValueInSub;
}

Nodo* Nodo::getRight(){
    return right;
}

Nodo* Nodo::getLeft(){
    return left;
}

Nodo* Nodo::getParent(){
    return parent;
}

int Nodo::getColor(){
    return color;
}

bool Nodo::checkNil(){
    return nilNode;
}

//Setter

void Nodo::setValueMin(int newValue){
    valueMin = newValue;
}

void Nodo::setValueMax(int newValue){
    valueMax = newValue;
}

void Nodo::setMaxValueInSub(int newValue){
    maxValueInSub = newValue;
}

void Nodo::setRight(Nodo* newRight){
    right = newRight;
}

void Nodo::setLeft(Nodo* newLeft){
    left = newLeft;
}

void Nodo::setParent(Nodo* newParent){
    parent = newParent;
}

void Nodo::setColor(int newColor){
    color = newColor;
}