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

    long long int sum = 0 , mod = (1e9)+7 , ans =0;
    void dfs(TreeNode* root){
        if(!root) return;
        sum+=root->val;
        dfs(root->left);
        dfs(root->right);
    }
    int solver(TreeNode *root){
        if(!root) return 0;
        long long int l =0 , r = 0;
        l+=solver(root->left);
        r+=solver(root->right);
        ans = max(ans,(((sum - (l+r+root->val))) * ((l+r+root->val))));
        // cout<<ans<<" "<<l<<" "<<r<<" "<<root->val<<endl;
        return (l+r+root->val);
    }
    int maxProduct(TreeNode* root) {
        dfs(root);
        int temp = solver(root);
        return ans%mod;
    }
};