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
    ListNode* oddEvenList(ListNode* head) {
        ios_base::sync_with_stdio(0);
        if(head==NULL || head->next==NULL) return head;
        ListNode *eh = head->next,*temp=head,*t=eh;
        while(temp){
            if(temp->next!=NULL and  temp->next->next!=NULL){
                temp->next = temp->next->next;
                temp = temp->next;
            } 
            else{
                temp->next=NULL;
                break;
            } 
            if(t->next!=NULL and t->next->next!=NULL){
                t->next = t->next->next;
                t=t->next;
            }
            else{
                t->next=NULL;
                break;
            }
        }
        temp=head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = eh;
        return head;
    }
};