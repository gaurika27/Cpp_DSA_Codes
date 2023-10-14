//Linked List
//2)Insert at head

#include <iostream>
using namespace std;

class node{
  public:
  int data;
  node* next;

  node(int val){
    data=val;
    next=NULL;
  }  
};

void insertAtHead(node* &head, int val){
  node* n= new node(val);
  n->next=head;
  head=n;
}

void display(node* head){
  node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
}

int main(){
  node* head=NULL;
  insertAtHead(head,5);
  insertAtHead(head,9);
  insertAtHead(head,10);
  display(head);
  return 0;
  
}