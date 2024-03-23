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
    ListNode* deleteMiddle(ListNode* head) {
        ios_base::sync_with_stdio(0);
        ListNode *s=head,*f=head;
        int l=0;
        while(s){
            s=s->next;
            l++;
            if(l>2) break;
        }
        if(l==1) return NULL;
        else if(l==2){
            head->next=NULL;
            return head;
        }
        s=head;
        while(f!=NULL and f->next!=NULL){
            s=s->next;
            f=f->next->next;
        }
        s->val = s->next->val;
        s->next = s->next->next;
        return head;
    }
};