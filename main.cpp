#include <iostream>
#include <cstring>
#include "node.h"


using namespace std;

int main() {

node* stackHead = new node(NULL);
node* queueHead = new node(NULL);


return 0;

}



void enqueue(node* head, node* insert) {
if(head == NULL) {
head = insert;
return;
}

if(head ->getNext() != NULL) {
enqueue(head -> getNext(), insert);

} else {
head->setNext(insert);
head->getNext()->setNext(NULL);

}
}

node* dequeue(node* head) {
if(head == NULL) {
return NULL;

} else {
node* temp = new node(head->getValue());
temp = head;
head= head->getNext();
return temp;

}



}


void push(node* head, node* insert) {
if(head == NULL) {
head = insert;

} else {
if(head->getNext() != NULL) {
push(head->getNext(), insert);
} else {
head->setNext(insert);
insert->setNext(NULL);

}

}

}

node*  pop(node* head) {
if(head == NULL) {
return NULL;
} else {
if(head->getNext()->getNext() != NULL) {
pop(head->getNext());

} else {
node* temp = new node(head->getNext()->getValue());
head->getNext()->setNext(NULL);
return temp;
}

}
return NULL;
}



