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
        unordered_map<int ,long long > mp;
        void solver(int i,TreeNode *root){
            if(!root) return;
            mp[i]+=root->val;
            solver(i+1,root->left);
            solver(i+1,root->right);
        }
public:
    
    long long kthLargestLevelSum(TreeNode* root, int k) {
        solver(0,root);
        if(mp.size() < k) return -1;
        priority_queue<long long ,vector<long long> , greater<long long >> pq;
        for(auto i:mp){
            pq.push(i.second);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};