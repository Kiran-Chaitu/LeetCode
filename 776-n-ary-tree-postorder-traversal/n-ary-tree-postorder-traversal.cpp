/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;
    void solver(Node* root){
        if(!root) return;
        for(Node* i:root->children){
            solver(i);
            ans.push_back(i->val);
        }
    }
    vector<int> postorder(Node* root) {
        // ios_base::sync_with_stdio(0);
        // cin.tie(NULL);
        if(!root)   return {};
        solver(root);
        ans.push_back(root->val);
        return ans;
    }
};