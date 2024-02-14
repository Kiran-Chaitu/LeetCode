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
    void insert(TreeNode *root,int n){
        TreeNode *nn = root;
        TreeNode *t = new TreeNode(n);
        while(nn){
            if(nn->val > n){
                if(nn->left == NULL){
                    nn->left=t;
                    break;
                }
                else nn=nn->left;
            }
            else{
                if(nn->right== NULL){
                    nn->right=t;
                    break;
                }
                else nn=nn->right;
            }
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = new TreeNode(preorder[0]);
        if(preorder.size()==1) return root;
        for(int i=1;i<preorder.size();i++){
            insert(root,preorder[i]);
        }
        return root;
    }
};