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

node* peek(node* &head, node * current) {
    
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


void shunt(char array[80], node* &stackHead, node* &queueHead, node* stack, node* queue) {
int i = 0;
for(i= 0; array[i] != '\0'; i++) {
if(isdigit(array[i]) == true) {
 
    
    char* data = new char(array[i]);
node* temp = new node(data);

enqueue(queueHead,queueHead ,temp);
    
  
    
    




} else if(array[i] == '+' || array[i] =='-' ||array[i] == '^' ||array[i] == '/' || array[i] == '*') {
    

    if(!isEmpty(stackHead)) {
        
        
       
    while((prec(*(peek(stackHead,stackHead)->getValue())) > prec(array[i]) || (prec(*(peek(stackHead,stackHead)->getValue())) == prec(array[i]) && associative(array[i]))) &&
          *(peek(stackHead,stackHead)->getValue()) != '(' ) {
       
       
      
         enqueue(queueHead,queueHead,peek(stackHead,stackHead));
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
    
    
  

    
    
    
    
    
   
while(*(peek(stackHead,stackHead) -> getValue()) != '(') {
    
 
    
    
 
 enqueue(queueHead,queueHead,peek(stackHead,stackHead));
    
pop(stackHead,stackHead);
    
}
   

    
   
    
    
if(*(peek(stackHead,stackHead)->getValue()) == '(') {
    
   

pop(stackHead,stackHead);

    
 

}

}

}
    

    
  
    
    


        while(stackHead != NULL) {
            
            
           
            enqueue(queueHead,queueHead, peek(stackHead,stackHead));
            pop(stackHead,stackHead);
            
            
         
           
    
        }
    
    
    
    
  

/*
    while(queueHead != NULL) {
        cout << queueHead->getValue();
        queueHead = queueHead->getNext();
        
    }
    cout << endl;
*/
    return;


}




void buildTree(node* &queueHead,node* &treeHead,node* currentQueue,node* currentTree) {
    while(!isEmpty(queueHead)) {
        
        if(isdigit(*(queueHead->getValue()))) {
            node* temp = new node(queueHead->getValue());
            push(treeHead,treeHead,temp);
            dequeue(queueHead,queueHead);
            
            
            
        } else {
            node* temp = new node(queueHead->getValue());
            temp->setRight(peek(treeHead,treeHead));
            pop(treeHead,treeHead);
            temp->setLeft(peek(treeHead,treeHead));
            pop(treeHead,treeHead);
            push(treeHead,treeHead,temp);
            dequeue(queueHead,queueHead);
            
            
            
            
        }
        
        
    }
    
}


void infix(node * treeHead) {
    if(treeHead != NULL) {
    if(*(treeHead->getValue()) == '+' || *(treeHead->getValue()) == '-' || *(treeHead->getValue()) == '*' || *(treeHead->getValue()) == '/') {
        cout << "(";
    }
    if(treeHead->getLeft() != NULL) {
        infix(treeHead->getLeft());
    }
    cout << treeHead->getValue();
    if(treeHead->getRight() != NULL) {
        infix(treeHead->getRight());
    }
 
    
    if(*(treeHead->getValue()) == '+' || *(treeHead->getValue()) == '-' || *(treeHead->getValue()) == '*' || *(treeHead->getValue()) == '/') {
        cout << ")";
    }
    }
    
}


void prefix(node* treeHead) {
    if(treeHead != NULL) {
    cout << treeHead->getValue();
        if(treeHead -> getLeft() != NULL) {
            prefix(treeHead->getLeft());
        }
        if(treeHead->getRight() != NULL) {
            prefix(treeHead->getRight());
            
        }
    
    }
    
}


void postfix(node* treeHead) {
    if(treeHead != NULL) {
    if(treeHead->getLeft() != NULL) {
        postfix(treeHead->getLeft());
        
    }
    if(treeHead->getRight() != NULL) {
        postfix(treeHead->getRight());
    }
    cout << treeHead->getValue();
        
    }
    
    
}


int main() {
    
    node* stackHead = new node(NULL);
    node* queueHead = new node(NULL);

    node* treeHead = new node(NULL);
    treeHead = NULL;
    stackHead = NULL;
    queueHead = NULL;

    
    
    cout << "Enter a mathematical expression in infix notation." << endl;
    char input[80];
    cin.get(input, 80);
    cin.get();
    shunt(input,stackHead,queueHead, stackHead,queueHead);
    buildTree(queueHead,treeHead,queueHead,treeHead);
    cout << "If you would like to output in postfix type: 'post'. IF you would like to ouput in prefix type 'pre'. If you would like to output in infix type 'in'"
    
    
    return 0;
    
}











