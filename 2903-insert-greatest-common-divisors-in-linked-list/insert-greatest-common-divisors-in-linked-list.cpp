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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        if(head->next==NULL) return head;
        ListNode* t=head;
        while(t->next!=NULL){
            int res=__gcd(t->val,t->next->val);
            ListNode *nx=t->next;
            ListNode *nn = new ListNode(res);
            t->next=nn;
            t=t->next;
            t->next=nx;
            t=t->next;
        }
        return head;
    }
};