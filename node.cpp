/*
 Following is the node.cpp file for the node class. Defines the functions that will be essential for the program
 By:Deyvik Bhan
 date: 2/04/20
 
 
 */

#include <iostream>
#include <cstring>
#include "node.h"

// Constrcuctor
node::node(char* newData) {
value = newData;
next = NULL;
left = NULL;
right = NULL;

}

// All of the other functions either set the next,left or right pointer
void node::setNext(node* newNext) {
next = newNext;

}

void node::setLeft(node* newLeft) {
left = newLeft;


}

void node::setRight(node* newRight) {
right = newRight;

}

node* node::getNext() {
return next;

}

node* node::getLeft() {
return left;

}

node* node::getRight() {
return right;

}


char* node::getValue() {
return value;

}
