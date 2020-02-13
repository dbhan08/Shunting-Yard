#include <iostream>
#include <cstring>
#include "node.h"


using namespace std;




void enqueue(node* &head,node* current, node* insert) {
if(head == NULL) {

head = insert;

return;
}

if(head ->getNext() != NULL) {
enqueue(head,current->getNext(), insert);

} else {
current->setNext(insert);
current->getNext()->setNext(NULL);

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

node* peek(node* head) {
if(head->getNext() != NULL) {
peek(head->getNext());
} else {
return head->getNext();

}

return NULL;
}


node* getTail(node* head) {
    if(head->getNext() != NULL) {
        getTail(head->getNext());
        
    } else {
        return head;
        
    }
    return NULL;
    
}



bool associative(char c) {
    if(c == '^') {
        
        return false;
        
    } else {
        
        return true;
        
    }
    
    
    
}





int prec(char first) {
    if(first == '^') {
        return 3;
        
        
    } else if(first == '*'|| '/') {
        return 2;
        
    } else {
       return 1;
        
    }
    
    
    
}


void shunt(char array[80], node* &stackHead, node* &queueHead) {
int i = 0;
for(i= 0; array[i] != '\0'; i++) {
if(isdigit(array[i]) == true) {
char* data = new char[50];
data = &array[i];
node* temp = new node(data);
   
enqueue(queueHead,queueHead ,temp);
    cout << queueHead->getValue();

   


// ||
   //
} else if(array[i] == '+' || '-' || '^' || '/' || '*') {
    return;
    
    while((prec(*(stackHead->getValue())) >  prec(array[i])) || (prec(*(stackHead->getValue())) == prec(array[i] && associative(array[i])))) {
        pop(stackHead);
        enqueue(queueHead,queueHead,stackHead);
        
        
    }
        
        
        
    
        
        
        
        
    



} else if(array[i] == '(' ) {
char* data = new char[50];
data = &array[i];
node* temp = new node(data);
push(stackHead, temp);


} else if(array[i] == ')') {

    char* leftParen = new char[50];
    leftParen[1] = '(';
while(*(getTail(stackHead) -> getValue()) != '(') {
pop(stackHead);
enqueue(queueHead,queueHead,stackHead);

}
if(*(getTail(stackHead)->getValue()) == ')') {
pop(stackHead);

}




}



if(array[i] == '\0') {
while(stackHead != NULL) {
pop(stackHead);
enqueue(queueHead,queueHead,stackHead);



}

}




}
    
    
  
    
   
    return;


}


int main() {
    
    node* stackHead = new node(NULL);
    node* queueHead = new node(NULL);
    stackHead = NULL;
    queueHead = NULL;
    
    
    cout << "Enter a mathematical expression in infix notation." << endl;
    char input[80];
    cin.get(input, 80);
    cin.get();
    shunt(input,stackHead,queueHead);
    
    
    return 0;
    
}











