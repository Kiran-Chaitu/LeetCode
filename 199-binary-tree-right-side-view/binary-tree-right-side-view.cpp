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
    
    vector<vector<int>> level(TreeNode *root){
        if(!root) return {};
        vector<vector<int>> v;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> dum;
            for(int i=0;i<n;i++){
                TreeNode *nn= q.front();
                if(nn->left!=NULL) q.push(nn->left);
                if(nn->right!=NULL) q.push(nn->right);
                dum.push_back(nn->val);
                q.pop();
            }
            v.push_back(dum);
        }
        return v;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> ans=level(root);
        vector<int> v;
        for(auto i:ans){
            int n=i.size();
            v.push_back(i[n-1]);
        }
        return v;
    }
};