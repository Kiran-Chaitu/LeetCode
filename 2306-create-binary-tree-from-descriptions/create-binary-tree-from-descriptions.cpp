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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        for(int i=0;i<descriptions.size();i++){
            if(mp.find(descriptions[i][0])==mp.end()){
                TreeNode *nn = new TreeNode(descriptions[i][0]);
                mp[descriptions[i][0]] = nn;
            }
            if(mp.find(descriptions[i][1])==mp.end()){
                TreeNode *nn = new TreeNode(descriptions[i][1]);
                mp[descriptions[i][1]] = nn;
            }
            if(descriptions[i][2]){
                mp[descriptions[i][0]]->left = mp[descriptions[i][1]];
            }
            else mp[descriptions[i][0]]->right = mp[descriptions[i][1]];
        }
        TreeNode *root;
        unordered_map<int,int> tp;
        for(int i=0;i<descriptions.size();i++){
            tp[descriptions[i][1]]=1;
        }
        for(auto i:mp){
            if(tp.find(i.first) == tp.end()){
                root=i.second;
                break;
            }
        }
        return root;
    }
};