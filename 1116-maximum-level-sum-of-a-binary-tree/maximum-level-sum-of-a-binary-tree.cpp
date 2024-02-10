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
    int levelOrder(TreeNode* root) {
        if(!root) return 0;
        if(root->left==NULL and root->right==NULL) return 1;
        int maxi=INT_MIN,mxl;
        queue<TreeNode *>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            int sum=0;
            level++;
            for(int i=0;i<n;i++){
                TreeNode *nn=q.front();
                if(nn->left!=NULL)q.push(nn->left);
                if(nn->right!=NULL)q.push(nn->right);
                sum+=nn->val;
                q.pop();
            }
            if(sum>maxi){
                maxi=sum;
                mxl=level;
            }
        }
        return mxl;
    }
    int maxLevelSum(TreeNode* root) {
        int ans=levelOrder(root);
        return ans;
    }
};