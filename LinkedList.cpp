#include <cstdlib>
#include <iostream>

struct Node{
  int val;
  struct Node* nextnode;

};


void viewList(Node *n){
  Node* temp=n;
  if(temp != NULL){
    while( temp->nextnode != NULL){
      std::cout << temp->val;
      temp=temp->nextnode;
      
    }  
    std::cout << temp->val;
    std::cout << "\n linkedlist elements";
  }
}
Node* insertHead(Node *head, Node *element){
  element->nextnode=head;
  return element;  
}
Node* push(Node *head, Node *element){
  Node* n=head;
  if(n ==NULL){
    return element;
  }
  while(n->nextnode!=NULL){
    n=n->nextnode;
  }
  n->nextnode=element;
  element->nextnode=NULL;
  return head;
}
Node* replaceHead(Node *head, Node* element){
  element->nextnode=head->nextnode;
  head=element;
  return head;
}
Node* deleteHead(Node *head){
  Node* temp=head->nextnode;
  head=temp;
  return head;
}
Node* insertIndex(Node* head, Node* element, int index){
  int iter=0;
  if(index==0){ head=insertHead(head,element); return head;}
  Node* prev=head; iter=1;
  Node* temp=head;temp=temp->nextnode;
  while(temp!=NULL){
    if(iter==index){
      std::cout <<"added";
      prev->nextnode=element;
      element->nextnode=temp;
      break;
      
    }
    std::cout<<"itered";
    prev=temp;
    temp=temp->nextnode;
    iter++;
  }
  return head;
}
Node* replaceIndex(Node* head, Node* element, int index){
  Node* temp=head;temp=temp->nextnode;
  Node* prev=head;
  int iter=0;
  if(index == iter){return replaceHead(head,element);}
  iter=1;

  while(temp != NULL){
    if(iter==index){
      prev->nextnode=element;
      element->nextnode=temp->nextnode;
      temp=NULL;
      break;
    }
    
    temp=temp->nextnode;
    prev=prev->nextnode;
    iter++;
  }
  return head;
}
Node* deleteIndex(Node* head, int index){
  Node* temp=head;temp=temp->nextnode;
  Node* prev=head;
  int iter=0;
  if(iter==index){return head->nextnode;}
  iter=1;
  while(temp -> nextnode!=NULL){
    if(index == iter){
      prev->nextnode=temp->nextnode;
      temp->nextnode=NULL;
      temp=NULL;
      break;
    }
    prev=prev->nextnode;
    temp=temp->nextnode;
    iter++;
  }
  return head;
}
Node* reverseList(Node* head){
  Node* temp=head;
  Node* next=NULL;Node*prev=NULL;
  while(temp !=NULL){
    next=temp->nextnode;
    temp->nextnode=prev;
    prev=temp;
    temp=next;
    
  }
  head=prev;
  return head;
}

  

int main() {
  Node *n= new Node;
  Node *second= new Node;
  Node *third= new Node;
  Node *fourth= new Node;
  Node *insertedNode=new Node;

  n->nextnode=second;
  n->val=5;
  second->val=6;
  second->nextnode=third;
  
  insertedNode->val=9;
  n=replaceIndex(n,insertedNode,1);
  viewList(n);
}