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
    void inorder(TreeNode* root , map<int,vector<pair<int,int>>> &mp ,int balanceFactor , int level){
        if(!root) return;
        mp[balanceFactor].push_back({level , root->val});
        inorder(root->left , mp , balanceFactor-1 , level+1);
        inorder(root->right , mp, balanceFactor+1 , level+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> mp;
        int balanceFactor =0 , level = 0;
        inorder(root , mp , balanceFactor , level);
        vector<vector<int>> ans;
        for(auto i : mp){
            vector<pair<int,int>> v = i.second;
            sort(v.begin() , v.end() , [](pair<int,int> &a , pair<int,int> &b){
                if(a.first == b.first) return a.second < b.second;
                return a.first < b.first;
            });
            vector<int> temp;
            for(auto j:v){
                temp.push_back(j.second);
            }
            ans.push_back(temp);
        }
        return ans;
    } 
};