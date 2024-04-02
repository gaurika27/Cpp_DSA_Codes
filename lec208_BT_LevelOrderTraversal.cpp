#include <bits\stdc++.h>
using namespace std;

class node{
  public:
    int data;
    node* left;
    node* right;

  node(int d){
    this->data=d;
    this->left=NULL:
    this->right=NULL;
  }
};
node* buildTree(node* root){
  cout<<"Enter data: "<<endl;
  int data;
  cin>>data;
  root=new node(data);
  if(data=-1) return NULL;
  cout<<"Enter data for left child: "<<endl;
  root->left=buildTree(root->left);
  cout<<"Enter data for right child: "<<endl;
  root->right=buildTree(root->right);
  return root;
}

void levelOrderTransversal(node* root){
  queue<node*> q;
  q.push(root);
  while(!q.empty()){
    node* temp=q.front();
    q.pop();
    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);    
  }
}

int main(){
  node* root=NULL;
  root=buildTree(); //creating a tree
}