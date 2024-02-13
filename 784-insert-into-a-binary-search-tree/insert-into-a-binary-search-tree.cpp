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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *nn = new TreeNode(val);
        if(!root) return nn;
        TreeNode *temp=root;
        while(temp){
            if(temp->val < val and temp->right!=NULL)
            {
                temp=temp->right;
            }
            else if(temp->val < val and temp->right==NULL ){
                    temp->right=nn;
                    break;
            }
            else if(temp->val > val and temp->left!=NULL) temp=temp->left;
            else {
                temp->left=nn;
                break;
            }
        } 
        return root;
    }
};