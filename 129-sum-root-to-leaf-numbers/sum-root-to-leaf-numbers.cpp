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
    // Code Written By ___Kiran__Chaitu___
    int sum=0;
    void preorder(TreeNode *root,int dig){
        if(!root) return;
        dig  = dig *10 + root->val;
        if(root->left==NULL and root->right==NULL) sum+=dig;
        preorder(root->left,dig);
        preorder(root->right,dig);
    }
    int sumNumbers(TreeNode *root) {
        preorder(root,0);
        return sum;
    }
};