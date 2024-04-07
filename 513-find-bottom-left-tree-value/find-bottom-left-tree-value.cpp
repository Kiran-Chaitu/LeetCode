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
    void fun(map<int,vector<int>>&mp,TreeNode* root,int level){
        if(root==NULL) return;
        mp[level].push_back(root->val);
        fun(mp,root->left,level+1);
        fun(mp,root->right,level+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        map<int,vector<int>>mp;
        fun(mp,root,0);
        return mp[mp.size()-1][0];
    }
};