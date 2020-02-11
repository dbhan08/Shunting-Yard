#ifndef node_H
#define node_H

#include <iostream>
#include <cstring>
using namespace std;


class node {
public:

node(char* k);
~node();
       
void setNext(node*);
node* getNext();
void setRight(node*);
void setLeft(node*);
node* getLeft(); 
node* getRight();
char* getValue();

private:

char* value;
node* next;
node* right;
node* left;

};
#endif
