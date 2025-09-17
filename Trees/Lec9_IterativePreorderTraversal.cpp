class Solution{
  public:
  vector<int> preOrderTraversal(TreeNode* root){
    vector<int> preorder;
    if(root==NULL) return preorder;
    
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
      root=st.temp();
      st.pop();
      preorder.push_back(root->val);
      if(root->right!=NULL){
        st.push(root->right);
      }
      if(root->left!=NULL){
        st.push(root->left)
      }
    }
    return preorder;
  }
};
