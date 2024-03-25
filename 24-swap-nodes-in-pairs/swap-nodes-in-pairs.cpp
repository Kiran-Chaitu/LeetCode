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
    ListNode* swapPairs(ListNode* head) {
        ios_base::sync_with_stdio(0);
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        ListNode *t = head,*nx = head->next,*p=NULL;
        head = head->next;
        while(t!=NULL){
            t->next = nx->next;
            nx->next = t;
            if(p!=NULL) p->next=nx;
            p=t;
            t=t->next;
           if(t!=NULL and t->next!=NULL) nx = t->next;
           else break;
        }
        return head;
    }
};