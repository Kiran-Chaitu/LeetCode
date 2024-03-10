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
    void solver(TreeNode *root, int val , int depth , int cur){
        if(!root) return ;
        if(depth == cur){
            TreeNode  *nl = new TreeNode(val);
            TreeNode  *nr = new TreeNode(val);
            nl->left = root->left;
            nr -> right = root -> right;
            root -> left = nl;
            root -> right = nr;
            return;
        }
        solver(root->left , val ,depth , cur+1 );
        solver(root->right , val ,depth , cur+1 );
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        ios_base::sync_with_stdio(0);
        if(depth ==1 ){
            TreeNode *nn = new TreeNode(val);
            nn->left  = root;
            return nn;
        }
        else{
            solver(root,val,depth-1,1);
            return root;
        }
        return root;
    }
};