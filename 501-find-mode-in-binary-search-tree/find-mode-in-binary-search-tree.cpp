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
    int maxi = -1;
    void dfs(TreeNode *root,unordered_map<int,int> &mp){
        if(!root) return;
        mp[root->val]++;
        maxi = max(maxi, mp[root->val]);
        dfs(root->left ,mp);
        dfs(root->right ,mp);
    }
    void dfs(TreeNode *root,unordered_map<int,int> &mp, vector<int> &ans){
        if(!root) return;
        if(mp[root->val] == maxi){ 
            ans.push_back(root->val);
            mp.erase(root->val);
        }
        dfs(root->left ,mp, ans);
        dfs(root->right ,mp , ans);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mp;
        dfs(root,mp);
        vector<int> ans;
        dfs(root,mp,ans);
        return ans;
    }
};