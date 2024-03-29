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
        ios_base::sync_with_stdio(0);
        if(!root) return {};
        if(root->left==NULL and root->right==NULL) return {{root->val}};
        vector<vector<int>> ans;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> v;
            for(int i=0;i<n;i++){
                TreeNode *nn=q.front();
                if(nn->left!=NULL)q.push(nn->left);
                if(nn->right!=NULL)q.push(nn->right);
                v.push_back(nn->val);
                q.pop();
            }
            ans.push_back(v);
        }
        return ans;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        vector<vector<int> > ans= levelOrder(root);
        for(int i=1;i<ans.size();i+=2){
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};