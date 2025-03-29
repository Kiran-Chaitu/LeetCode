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
    private:
        long long int kc;
        long long int traverse(TreeNode *root){
            if(!root) return 0;
            long long int ls =0 , rs=0 ,maxi,val = root->val;
            ls = traverse(root->left);
            rs = traverse(root->right);
            maxi = max(ls + rs + val , max(val+ls , max(val + rs , val)));
            kc = max(kc , maxi);
            return max(val + ls , max(val + rs , val));
        }
public:

    int maxPathSum(TreeNode* root) {
        kc = root->val;
        int temp = traverse(root);
        return kc;
    }
};