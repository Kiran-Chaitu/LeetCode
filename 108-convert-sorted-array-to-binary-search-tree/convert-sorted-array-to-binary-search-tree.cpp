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
    TreeNode* solver(int l,int r,vector<TreeNode*> &v){
        if(l>r) return NULL;
        int mid = (l+r)/2;
        v[mid]->left = solver(l,mid-1,v);
        v[mid]->right = solver(mid+1,r,v);
        return v[mid];
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        vector<TreeNode*> v;
        for(int i=0;i<nums.size();i++){
            TreeNode *temp = new TreeNode(nums[i]);
            v.push_back(temp);
        }
        return solver(0,nums.size()-1,v);
    }
};