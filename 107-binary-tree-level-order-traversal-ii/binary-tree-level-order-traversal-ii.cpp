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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> v; 
        if(root->left==NULL and root->right==NULL){
            vector<int> te;
            te.push_back(root->val);
            v.push_back(te);
            return v;
        } 
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            vector<int> t;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode *nn=q.front();
                if(nn->left!=NULL)  q.push(nn->left);
                if(nn->right!=NULL) q.push(nn->right);
                t.push_back(nn->val);
                q.pop();
            }
            v.push_back(t);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};