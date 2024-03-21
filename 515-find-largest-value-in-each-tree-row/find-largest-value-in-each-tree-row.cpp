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
    vector<int> largestValues(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        if(!root) return {};
        vector<int> ans;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int maxi = INT_MIN;
            for(int i=0;i<n;i++){
                TreeNode *nn=q.front();
                if(nn->left!=NULL)q.push(nn->left);
                if(nn->right!=NULL)q.push(nn->right);
                if(maxi < nn->val) maxi = nn->val;
                q.pop();
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};