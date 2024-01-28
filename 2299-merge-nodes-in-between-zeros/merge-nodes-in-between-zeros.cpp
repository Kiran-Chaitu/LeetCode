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
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *t=head;
        t=t->next;
        while(t){
            if(t->next->val!=0){
                t->val+=t->next->val;
                t->next=t->next->next;
            }
            else if(t->next->val==0){
                t->next=t->next->next;
                t=t->next;
            }

        }
        return head->next;
    }
};