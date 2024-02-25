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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        if(head->next == NULL) return head;
        int l=0;
        ListNode *t= head,*rh;
        while(t){
            l++;
            t =t->next;
        }
        int ans = k % l;
        if(ans == 0 ) return head;
        int rm = l-ans;
        int c=1;
        t=head;
        while(c<rm){
            c++;
            t=t->next;
        }
        rh = t->next;
        t->next=NULL;
        t=rh;
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=head;
        return rh;

    }
};