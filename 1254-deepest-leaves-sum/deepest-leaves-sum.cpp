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
    int sum=0; 
    int len(TreeNode *root){
        if(root==NULL) return 0;
        int lh=len(root->left);
        int rh=len(root->right);
        return max(lh,rh)+1;
    }
    void sumNodes(TreeNode *root,int l,int c){
        if(root==NULL) return;
        sumNodes(root->left,l,c+1);
        if(l==c) sum+=root->val;
        sumNodes(root->right,l,c+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        int maxi=len(root);
        cout<<maxi;
        //int sum=0;
        sumNodes(root,maxi,1);
        return sum;
    }
};