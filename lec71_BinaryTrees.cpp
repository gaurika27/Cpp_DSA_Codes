//Binary trees
#include <iostream>
using namespace std;

struct Node{
  int data;
  struct Node* left;
  struct Node* right;

  Node (int val){
    data=val;
    left=right=NULL;
  }
}; 

int main(){
  //Insertion
  Node* root=new Node(1);
  root->left=new Node(2);
  root->right=new Node(3);

  root->left->left=new Node(4);

  //Traversal:Breadth First Search(BFS) and Depth First Search(DFS)
  //DFS: Inorder Traversal(Left->Root->Right), Pre order Traversal(Root->Left->Right) Post order traversal(LEft->Right->Root)
  
  return 0;

}