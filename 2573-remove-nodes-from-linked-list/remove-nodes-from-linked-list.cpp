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
    ListNode* removeNodes(ListNode* head) {
        ListNode *t=head,*prev=NULL;
        while(t){
            ListNode *c=t->next;
            t->next=prev;
            prev=t;
            t=c;
        }
        head=prev;
        while(prev->next!=NULL){
            if(prev->val>prev->next->val) prev->next=prev->next->next;
            else prev=prev->next;
        }
        t=head;
        prev=NULL;
        while(t){
            ListNode *c=t->next;
            t->next=prev;
            prev=t;
            t=c;
        }
        return prev;
    }
};