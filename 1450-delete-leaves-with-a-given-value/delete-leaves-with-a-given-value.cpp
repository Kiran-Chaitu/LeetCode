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
    int flag=1;
    bool checknode(TreeNode *root){
        if(root->left==NULL and root->right==NULL) return true;
        return false;
    }
    void myorder(TreeNode *root,int target){
        if(!root) return;
        if(root->left!=NULL and checknode(root->left)  and root->left->val == target){
            root->left=NULL;
            flag=1;
        }
        if(root->right!=NULL and checknode(root->right) and root->right->val == target){
            root->right=NULL;
            flag=1;
        } 
        myorder(root->left,target);
        myorder(root->right,target);
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        while(flag){
            flag=0;
            myorder(root,target);
        }
        if(root->val==target and root->left==NULL and root->right==NULL) return NULL;
        return root;
    }
};