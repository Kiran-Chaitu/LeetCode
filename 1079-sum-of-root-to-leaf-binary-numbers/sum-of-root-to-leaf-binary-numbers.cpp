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
    void solver(TreeNode *root, int &sum , string ans){
        if(!root) return;
        if(root->left == nullptr and root->right == nullptr){
            ans+=to_string(root->val);
            int temp =0 , n = ans.size();
            // cout<<ans<<endl;
            for(int i = 0 , j = n-1;i < n and j>=0 ; i++ , j--){
                if(ans[i]=='1') temp+=pow(2,j);
            }
            sum+=temp;
            return;
        }
        ans+=to_string(root->val);
        solver(root->left,sum , ans);
        solver(root->right , sum , ans);
    }
    int sumRootToLeaf(TreeNode* root) {
        int sum =0 ;
        string ans ="";
        solver(root , sum , ans);
        return sum;
    }
};