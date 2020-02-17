/*Following is the node.h file for the node class. Has next pointers as well as left and right pointers
 By:Deyvik Bhan
 Date: 2/04/20
 */

#ifndef node_H
#define node_H

#include <iostream>
#include <cstring>
using namespace std;


class node {
public:

node(char* k);
~node();
// Following functions all have to do with getting or setting the next,left or right pointers
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
