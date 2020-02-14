#include <iostream>
#include <cstring>
#include "node.h"


using namespace std;

bool isEmpty(node* head) {
    
    if(head == NULL) {
        
        return true;
        
    }
    return false;
    
}


void enqueue(node* &head,node* current, node* insert) {
    
if(head == NULL) {

head = insert;
   

return;
}

if(current ->getNext() != NULL) {

enqueue(head,current->getNext(), insert);

} else {

current->setNext(insert);
  

insert->setNext(NULL);

}
}

node* dequeue(node* &head, node* current) {
if(head == NULL) {
return NULL;

} else if(head->getNext() == NULL) {
    head = NULL;
    return NULL;
        
        
} else {

head= current->getNext();
return current;

}



}


void push(node* &head,node* current, node* insert) {
if(head == NULL) {
head = insert;

} else {
if(current->getNext() != NULL) {
push(head,current->getNext(), insert);
} else {
current->setNext(insert);
insert->setNext(NULL);

}

}

}

node*  pop(node* &head,node*current) {
if(head == NULL) {
return NULL; 
} else if(current->getNext() == NULL) {
    head = NULL;
    return NULL;
        
        
} else {
if(current->getNext()->getNext() != NULL) {
pop(head, current->getNext());

} else {

current->getNext()->setNext(NULL);
return current->getNext();
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
     
        cout << "1" << endl;
        
        getTail(head->getNext());
        
    } else {
       
        cout << "2" << endl;
        
        
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
 
    cout << "a" << endl;
    char* data = new char(array[i]);
node* temp = new node(data);

enqueue(queueHead,queueHead ,temp);
    
    
   
 



} else if(array[i] == '+' || array[i] =='-' ||array[i] == '^' ||array[i] == '/' || array[i] == '*') {
    
    cout << "b" << endl;
    if(!isEmpty(stackHead)) {
    while((prec(*(stackHead->getValue())) > prec(array[i]) || (prec(*(stackHead->getValue())) == prec(array[i]) && associative(array[i]))) && *(stackHead->getValue()) != '(' && (!isEmpty(stackHead))) {
        cout << "c" << endl;
      
         enqueue(queueHead,queueHead,stackHead);
        pop(stackHead,stackHead);
        cout << "d" << endl;
       
      
        
    }
        
    
    }
    
        cout << "l" << endl;
    char* data = new char(array[i]);
    node* temp = new  node(data);
    cout << "y" << endl;
 
    push(stackHead,stackHead, temp);
    
    
} else if(array[i] == '(' ) {
  
char* data = new char(array[i]);

node* temp = new node(data);
push(stackHead,stackHead ,temp);
    cout << "e" << endl;
    
  
    
   
    
   
 


} else if(array[i] == ')') {
    
    cout << "f" << endl;
   
while(*(getTail(stackHead) -> getValue()) != '(') {
  
pop(stackHead,stackHead);
enqueue(queueHead,queueHead,stackHead);

    cout << "h" << endl;

}
    
    cout << "q" << endl;
if(*(getTail(stackHead)->getValue()) == '(') {
    cout << "i" << endl;
pop(stackHead,stackHead);
    
    cout << "j" << endl;

}
  cout << "g" << endl;
}

}
    

        
        while(stackHead != NULL) {
            cout << "z" << endl;
            enqueue(queueHead,queueHead,stackHead);
            pop(stackHead,stackHead);
            
            
        }
        
    
    
    
  

    
    while(queueHead!= NULL) {
        cout << queueHead->getValue();
        queueHead = queueHead->getNext();
        
    }
    cout << endl;
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











