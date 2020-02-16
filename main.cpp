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
    int count = 0;
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
    node* temp = new node(insert->getValue());
current->setNext(temp);
temp->setNext(NULL);


}

}

}

node*  pop(node* &head,node*current) {
    
    
    
    if(head == NULL) {
        return NULL;
    }
    
    
     else if(current ->getNext() != NULL) {
      
        
         while(current->getNext()->getNext() != NULL) {
             current = current->getNext();
            
         }
        
         node* temp = new node(NULL);
         temp = NULL;
         current->setNext(temp);
   
         

         
         return current;
        
     } else if(current->getNext() == NULL) {
     
      
         head = NULL;
     }
    
       return current;
    
}

node* peek(node* &head, node * current, node* &tail) {
    
    if(head == NULL) {
        return NULL;
    }
    while(current->getNext() != NULL) {
        
  
        current = current->getNext();
        
    }
    
    

    return current;

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
        
        
    } else if(first == '*'||first == '/') {
        return 2;
        
    } else {
       return 1;
        
    }
    
    
    
}


void shunt(char array[80], node* &stackHead, node* &queueHead, node* &stackTail, node* &queueTail, node* stack, node* queue) {
int i = 0;
for(i= 0; array[i] != '\0'; i++) {
if(isdigit(array[i]) == true) {
 
    
    char* data = new char(array[i]);
node* temp = new node(data);

enqueue(queueHead,queueHead ,temp);
    
  
    
    




} else if(array[i] == '+' || array[i] =='-' ||array[i] == '^' ||array[i] == '/' || array[i] == '*') {
    

    if(!isEmpty(stackHead)) {
        
        
       
    while((prec(*(peek(stackHead,stackHead,stackTail)->getValue())) > prec(array[i]) || (prec(*(peek(stackHead,stackHead,stackTail)->getValue())) == prec(array[i]) && associative(array[i]))) &&
          *(peek(stackHead,stackHead,stackTail)->getValue()) != '(' ) {
       
       
      
         enqueue(queueHead,queueHead,peek(stackHead,stackHead,stackTail));
        pop(stackHead,stackHead);
        
     
        if(isEmpty(stackHead)) {
            
            break;
        }
       
      
        
    }
        
        
      
 
       
       
        char* data = new char(array[i]);
        node* temp = new node(data);
  
        
        push(stackHead,stackHead,temp);
        
      
      
      
        
    
    } else {
    
      
    char* data = new char(array[i]);
    node* temp = new  node(data);
    
 
    push(stackHead,stackHead, temp);
      
    
        
        
        
     
        
        
    }
    
} else if(array[i] == '(' ) {
  
char* data = new char(array[i]);

node* temp = new node(data);
push(stackHead,stackHead ,temp);
  
 
    


    
  
 
    
    
   
 


} else if(array[i] == ')') {
    
    
  

    
    
    
    
    
   
while(*(peek(stackHead,stackHead,stackTail) -> getValue()) != '(') {
    
 
    
    
 
 enqueue(queueHead,queueHead,peek(stackHead,stackHead,stackTail));
    
pop(stackHead,stackHead);
    
}
   

    
   
    
    
if(*(peek(stackHead,stackHead,stackTail)->getValue()) == '(') {
    
   

pop(stackHead,stackHead);

    
 

}

}

}
    

    
  
    
    


        while(stackHead != NULL) {
            
            
           
            enqueue(queueHead,queueHead, peek(stackHead,stackHead,stackTail));
            pop(stackHead,stackHead);
            
            
         
           
    
        }
    
    
    
    
  


    while(queueHead != NULL) {
        cout << queueHead->getValue();
        queueHead = queueHead->getNext();
        
    }
    cout << endl;

    return;


}


int main() {
    
    node* stackHead = new node(NULL);
    node* queueHead = new node(NULL);
    node* stackTail = new node(NULL);
    node* queueTail = new node(NULL);
    stackHead = NULL;
    queueHead = NULL;
    stackTail = NULL;
    queueTail = NULL;
    
    
    cout << "Enter a mathematical expression in infix notation." << endl;
    char input[80];
    cin.get(input, 80);
    cin.get();
    shunt(input,stackHead,queueHead,stackTail,queueTail, stackHead,queueHead);
    
    
    return 0;
    
}











