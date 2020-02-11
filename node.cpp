#include <iostream>
#include <cstring>
#include "node.h"


node::node(char* newData) {
value = newData;
next = NULL;
left = NULL;
right = NULL;

}


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
