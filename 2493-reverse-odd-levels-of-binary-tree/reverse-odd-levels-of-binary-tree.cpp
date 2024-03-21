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
        int k=0;
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
            if(k%2!=0) reverse(v.begin(),v.end());
            k++;
            ans.push_back(v);
        }
        return ans;
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        vector<vector<int> > v= levelOrder(root);
        queue<TreeNode *> q;
        q.push(root);
        int k=0;
        while(!q.empty()){
            int n=q.size();
            if(k%2!=0){
                for(int i=0;i<n;i++){
                    TreeNode *nn = q.front();
                    if(nn->left!=NULL) q.push(nn->left);
                    if(nn->right!=NULL) q.push(nn->right);
                    nn->val = v[k][i];
                    q.pop();
                }
            }
            else{
                for(int i=0;i<n;i++){
                    TreeNode *nn = q.front();
                    if(nn->left!=NULL) q.push(nn->left);
                    if(nn->right!=NULL) q.push(nn->right);
                    nn->val = v[k][i];
                    q.pop();
                }
            }
            k++;
        }
        return root;
    }
};