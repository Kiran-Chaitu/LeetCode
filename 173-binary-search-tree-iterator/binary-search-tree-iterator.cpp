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
class BSTIterator {
public:
    int t;
    vector<int> v;
    TreeNode *temp;
    int i=0,n;
    void inorder(TreeNode *root){
        if(!root) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    BSTIterator(TreeNode* root){
        temp=root;
        inorder(root);
        n=v.size();
    }
    int next() {
        return v[i++];
    }
    bool hasNext() {
        if(i>=n) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */