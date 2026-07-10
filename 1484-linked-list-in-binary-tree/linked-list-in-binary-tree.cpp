/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool temp= false,ans = false;
    bool listTraverse(TreeNode *root, ListNode *node){
        if(root== NULL || node == NULL) return false;
        if(root->val != node->val) return false;
        if(node->next == NULL and node->val == root->val) return true;
        return listTraverse(root->left, node->next) || listTraverse(root->right, node->next);
    }
    void inorder(TreeNode *root , ListNode *head){
        if(!root) return;
        if(root->val == head->val){
            temp = listTraverse(root, head);
            if(temp){
                ans = true;
                return;
            }
        }
        inorder(root->left, head);
        inorder(root->right , head);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        inorder(root, head);
        return ans;
    }
};