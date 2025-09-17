/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        // if(root->left == NULL && root->right == NULL){
        //     return {{root->val}};
        // }
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;

        while(!q.empty()){
            int s = q.size();
            vector<int> v;
            for(int i = 0 ; i < s ; i++){
                TreeNode* temp = q.front();
                // cout<<"temp value"<<temp->val<<endl;
                v.push_back(temp->val);
                q.pop();

                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            ans.push_back(v);
        }

        return ans;
    }
};
