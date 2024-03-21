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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        if(root->left==NULL and root->right==NULL) return {{root->val}};
        vector<vector<int>> ans;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> v;
            for(int i=0;i<n;i++){
                TreeNode *nn=q.front();
                if(nn->left!=NULL)q.push(nn->left);
                if(nn->right!=NULL)q.push(nn->right);
                v.push_back(nn->val);
                q.pop();
            }
            ans.push_back(v);
        }
        return ans;
    }
    vector<int> largestValues(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        vector<vector<int>> v = levelOrder(root);
        vector<int> ans;
        for(int i=0;i<v.size();i++){
            int maxi=INT_MIN;
            for(int j=0;j<v[i].size();j++){
                if(v[i][j] > maxi ) maxi = v[i][j];
                //cout<<v[i][j]<<" ";
            }
            //cout<<endl;
            ans.push_back(maxi);
        }
        return ans;
    }
};