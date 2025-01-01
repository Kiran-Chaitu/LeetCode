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
    vector<vector<int>> solver(TreeNode *root){
        if(!root) return {};
        if(root->left==NULL and root->right==NULL) return {{root->val}};
        vector<vector<int>> temp;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> v;
            TreeNode *t;
            for(int i=0;i<n;i++){
                t=q.front();
                if(t->left!=NULL)   q.push(t->left);
                if(t->right!=NULL)   q.push(t->right);
                v.push_back(t->val);
                q.pop();
            }
            temp.push_back(v);
        }
        return temp;
    }
    int minimumOperations(TreeNode* root) {
        int ans=0;
        vector<vector<int>> bfs = solver(root);
        for(int i=0;i<bfs.size();i++){
            cout<<endl;
            vector<int> temp=bfs[i],t=bfs[i];
            sort(temp.begin(),temp.end());
            unordered_map<int,int> mp;
            for(int j=0;j<temp.size();j++){
                mp[temp[j]] = j;
                //cout<<temp[j]<<" ";
            }
            // cout<<endl;
            // for(int j=0;j<temp.size();j++){
            //     cout<<t[j]<<" ";
            // }
            //cout<<"\n"<<endl;
            for(int j=0;j<t.size();j++){
                while(t[j]!=temp[j]){
                    ans++;
                    //cout<<t[j]<<" "<<t[mp[j]]<<endl;
                    //swap(t[j] , t[mp[t[j]]]);
                    int k = t[mp[t[j]]];
                    t[mp[t[j]]] = t[j];
                    t[j] = k;
                    //cout<<t[j]<<" "<<t[mp[t[j]]]<<endl;
                }
                //cout<<t[j]<<" ";
            }
            //cout<<endl;
        }
        return ans;
    }
};