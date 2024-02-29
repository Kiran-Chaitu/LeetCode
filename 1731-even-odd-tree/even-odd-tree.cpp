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
    bool isEvenOddTree(TreeNode* root) {
        vector<vector<int>> v=levelOrder(root);
        for(int i=0;i<v.size();i++){
            if(i&1){
                int ans=0;
                if(v[i].size()==1){
                    if(v[i][0]%2==0) ans=1;
                    else {
                        cout<<v[i][0]<<endl;
                        return 0;}
                }
                if(ans) continue;
                if(v[i][0]%2!=0) return 0; 
                for(int k=1;k<v[i].size();k++){
                    if((v[i][k]%2!=0 ) or (v[i][k-1] <= v[i][k]) ) {
                        cout<<v[i][k-1]<<" "<<v[i][k]<<endl;
                        return 0;
                    }
                }
            }
            else{
                int ans=0;
                if(v[i].size()==1){
                    if(v[i][0]%2!=0) ans=1;
                    else {
                        cout<<v[i][0]<<endl;
                        return 0;
                    }
                }
                if(ans) continue;
                if(v[i][0]%2==0) return 0; 
                for(int k=1;k<v[i].size();k++){
                    if((v[i][k]%2==0 ) or (v[i][k-1] >= v[i][k]) ) {
                        cout<<v[i][k-1]<<" "<<v[i][k]<<endl;
                    
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
};