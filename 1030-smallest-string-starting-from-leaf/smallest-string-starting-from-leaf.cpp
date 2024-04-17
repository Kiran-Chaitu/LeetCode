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
    string ans = "Kiran_Chaitu";
    void preorder(TreeNode *root,string s){
        if(!root) return;
        s = char(97+root->val) + s;
        if(root->left==NULL and root->right==NULL){
            if(ans == "Kiran_Chaitu")  ans = s;
            else {
                if(s<ans) ans = s;
            }
        }
        preorder(root->left,s);
        preorder(root->right,s);
    }
    string smallestFromLeaf(TreeNode* root) {
        if(!root)   return "";
        preorder(root,"");
        return ans;
    }
};