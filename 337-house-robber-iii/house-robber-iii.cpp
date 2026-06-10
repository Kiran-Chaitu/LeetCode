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
    int solver(TreeNode *root , unordered_map<TreeNode *,int> &dp){
        if(!root) return 0;
        if(dp.find(root)!=dp.end()) return dp[root];
        int pick = root->val;
        if(root->left) pick+=solver(root->left->left, dp)+ solver( root->left->right , dp);
        if(root->right) pick+= solver(root->right->left , dp) + solver(root->right->right, dp);
        int unPick = solver(root->left , dp ) + solver(root->right , dp);
        return dp[root] = max(pick , unPick);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode * , int > dp;
        return solver(root, dp);
    }
};