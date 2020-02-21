/*
 The following program is a shunting yard algorithim which can convert infix to postfix, then creates an expression tree and is able to convert that to infix postfix or prefix
 By:Deyvik Bhan
 Date:2/5/20
 
 
 
 */



#include <iostream>
#include <cstring>
#include "node.h"


using namespace std;


// Following function checks if stack or queue is empty

bool isEmpty(node* head) {
    
    if(head == NULL) {
        
        return true;
        
    }
    return false;
    
}

// Following function adds node to queue(adds node to the end of the linked list)
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


// Following function removes the first object from the queue(removes head of linked list)
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

// Follwing function adds node to the end of the stack(adds node to the end of the linked list)
void push(node* &head,node* current, node* &insert,node* left,node* right) {
    if(head == NULL) {
        head = insert;
        
    } else {
        if(current->getNext() != NULL) {
            push(head,current->getNext(), insert,insert->getLeft(),insert->getRight());
        } else {
            node* temp = new node(insert->getValue());
            current->setNext(temp);
            temp->setLeft(left);
            temp->setRight(right);
            temp->setNext(NULL);
            
            
        }
        
    }
    
}


//Following function removes node from the top of the stack(removes from end of the linked list(aka removes tail))
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


// Following function returns the top of the stack(returns the tail)
node* peek(node* &head, node * current) {
    
    if(head == NULL) {
        return NULL;
    }
    while(current->getNext() != NULL) {
        
        
        current = current->getNext();
        
    }
    
    
    
    return current;
    
}








// Following function checks if token is associative
bool associative(char c) {
    if(c == '^') {
        
        return false;
        
    } else {
        
        return true;
        
    }
    
    
    
}




// Following function returns the precedence of an operator(for order of operations)
int prec(char first) {
    
    
    if(first == '^') {
        return 3;
        
        
    } else if(first == '*'||first == '/') {
        return 2;
        
    } else {
        return 1;
        
    }
    
    
    
}


//Pseudocode gotten from https://en.wikipedia.org/wiki/Shunting-yard_algorithm

void shunt(char array[80], node* &stackHead, node* &queueHead, node* stack, node* queue) {
    int i = 0;
    // While there is a token to read
    for(i= 0; array[i] != '\0'; i++) {
        // If token is a digit
        if(isdigit(array[i]) == true) {
            
            
            char* data = new char(array[i]);
            node* temp = new node(data);
            
            // Add to output queue
            
            enqueue(queueHead,queueHead ,temp);
            
            
            
            
            
            
            // If token is an operator
            
        } else if(array[i] == '+' || array[i] =='-' ||array[i] == '^' ||array[i] == '/' || array[i] == '*') {
            
            // If stack is empty
            if(!isEmpty(stackHead)) {
                
                
                // While there is an operator on the top of the stack with greater precedence then the token or they have same precedence and the token is left associative and the top of the stack is not a left paren
                while((prec(*(peek(stackHead,stackHead)->getValue())) > prec(array[i]) || (prec(*(peek(stackHead,stackHead)->getValue())) == prec(array[i]) && associative(array[i]))) &&
                      *(peek(stackHead,stackHead)->getValue()) != '(' ) {
                    
                    
                    // Add top of stack to output queue and remove from the stack
                    enqueue(queueHead,queueHead,peek(stackHead,stackHead));
                    pop(stackHead,stackHead);
                    
                    
                    if(isEmpty(stackHead)) {
                        
                        break;
                    }
                    
                    
                    
                }
                
                
                
                
                
                
                char* data = new char(array[i]);
                node* temp = new node(data);
                
                // Push token to the end of the stack
                push(stackHead,stackHead,temp,temp->getLeft(),temp->getRight());
                
                
                
                
                
                
            } else {
                
                
                char* data = new char(array[i]);
                node* temp = new  node(data);
                
                // Push token to the end of the stack
                push(stackHead,stackHead, temp,temp->getLeft(),temp->getRight());
                
                
                
                
                
                
                
                
            }
            
            // If token is a left paren
        } else if(array[i] == '(' ) {
            
            char* data = new char(array[i]);
            
            node* temp = new node(data);
            // Push to the end of the stack
            push(stackHead,stackHead ,temp,temp->getLeft(),temp->getRight());
            
            
            
            
            
            
        } else if(array[i] == ')') {
            
            // While the top of the stack is not a left paren
            
            while(*(peek(stackHead,stackHead) -> getValue()) != '(') {
                
                
                // Add the top of the stack to the output queue and remove it from the end of the stack
                enqueue(queueHead,queueHead,peek(stackHead,stackHead));
                
                pop(stackHead,stackHead);
                
            }
            
            
            
            
            
            // If the top of the stack is a left paren
            if(*(peek(stackHead,stackHead)->getValue()) == '(') {
                
                
                // Remove it from the top of the stack
                pop(stackHead,stackHead);
                
                
                
            }
            
        }
        
    }
    
    // If there are no more tokens to read and there are still operators in the stack
    
    while(stackHead != NULL) {
        
        // Add to output queue and remove from stack
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



// Function below builds binary tree
// Pseudo code gotten from https://en.wikipedia.org/wiki/Binary_expression_tree
void buildTree(node* &queueHead,node* &treeHead,node* currentQueue,node* currentTree) {
    /*
    while(currentQueue!= NULL) {
        cout << currentQueue ->getValue();
        currentQueue= currentQueue->getNext();
        
    }
     */
    //cout << endl;
    // While queue is not empty
    while(queueHead!=NULL) {
        
        
        if(isdigit(*(queueHead->getValue()))) {
            
            // If value is operand
            node* temp = new node(queueHead->getValue());
         //   cout << temp->getValue() << endl;
            // Push to the tree stack and remove from queue
            push(treeHead,treeHead,temp,temp->getLeft(),temp->getRight());
            
            dequeue(queueHead,queueHead);
            
            
            
            
        } else {
            // If value is operator
            // Set stackhead to the right pointer for the operator node
            // Pop stackhead
            // Set the new stackHead as the left pointer for the operator node
            // Pop stackhead
            // Push the operator to the tree stack
            node* temp = new node(queueHead->getValue());
            //temp = queueHead;
            temp->setRight(peek(treeHead,treeHead));
            pop(treeHead,treeHead);
            temp->setLeft(peek(treeHead,treeHead));
            pop(treeHead,treeHead);
            push(treeHead,treeHead,temp,temp->getLeft(),temp->getRight());
            /*
            cout << temp->getValue() << "a" << endl;
            cout << temp->getLeft()->getValue() << "b" << endl;
            cout << temp->getRight()->getValue() << "c" << endl;
            
            cout << peek(treeHead,treeHead)->getValue() << "k" << endl;
            cout << peek(treeHead,treeHead)->getLeft()->getValue() << "k" << endl;
            cout << peek(treeHead,treeHead)->getRight()->getValue() << "k" << endl;
            */
            dequeue(queueHead,queueHead);
            
            
            
            
            
        }
        
        
    }
    
    
    
}

// Following function transverses the binary tree outputting it in infix
// Pseudo code gotten from https://en.wikipedia.org/wiki/Binary_expression_tree
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


// Following function transverses the binary tree outputting it in prefix
// Pseudo code gotten from https://en.wikipedia.org/wiki/Binary_expression_tree

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


// Following function transverses the binary tree outputting it in pstfix
// Pseudo code gotten from https://en.wikipedia.org/wiki/Binary_expression_tree

void postfix(node* treeHead) {
    
    if(treeHead->getLeft() != NULL) {
        postfix(treeHead->getLeft());
        
    }
    if(treeHead->getRight() != NULL) {
        postfix(treeHead->getRight());
    }
    cout << treeHead->getValue();
    
    
    
    
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
    cout << "If you would like to output in postfix type: 'post'. IF you would like to ouput in prefix type: 'pre'. If you would like to output in infix type: 'in'." << endl;
    char inp[50];
    cin.get(inp,50);
    cin.get();
    if(strcmp(inp,"post") == 0) {
        postfix(treeHead);
        cout << endl;
        
    }
    else if(strcmp(inp,"pre") == 0) {
        prefix(treeHead);
        cout << endl;
        
    }
    
    else if(strcmp(inp,"in") == 0) {
        infix(treeHead);
        cout << endl;
        
    }
    else {
        cout << "Enter a valid option!" << endl;
    }
    
    
    return 0;
    
}





