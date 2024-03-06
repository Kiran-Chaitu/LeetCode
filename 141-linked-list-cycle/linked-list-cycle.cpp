/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ios_base::sync_with_stdio(0);
        ListNode *s=head,*f=head;
        if(f==NULL) return 0;
        while(f and f->next){
            f=f->next->next;
            s=s->next;
            if(f==s) return 1;
        }
        return 0;
    }
};