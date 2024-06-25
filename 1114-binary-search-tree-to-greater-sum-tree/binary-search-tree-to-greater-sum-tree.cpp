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
    
    vector<int> v;
    int ind=0;
    void inorder(TreeNode *root){
        if(root==NULL) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    void changeorder(vector<int> &pr,TreeNode *root){
        if(root==NULL) return;
        changeorder(pr,root->left);
        root->val=pr[ind];
        ind++;
        changeorder(pr,root->right);

    }
    TreeNode* bstToGst(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        if(root->left==NULL and root->right==NULL){
            root->val=root->val+1;
            return root;
        }
        inorder(root);
        vector<int> pr;
        int sum=0;
        for(int i=0;i<v.size();i++) sum+=v[i];
        int prs=0;
        for(int i=0;i<v.size();i++){
            pr.push_back(sum-prs);
            prs+=v[i];
        }
        changeorder(pr,root);
        return root;
    }
};