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
    string ans = "";
    void preorder(TreeNode *root,string s){
        if(!root) return;
        s = char('a'+root->val) + s;
        if(root->left==NULL and root->right==NULL){
            if(ans == "")  ans = s;
            else {
                if(s<ans) ans = s;
            }
        }
        preorder(root->left,s);
        preorder(root->right,s);
    }
    string smallestFromLeaf(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        if(!root)   return "";
        preorder(root,"");
        return ans;
    }
};