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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp= new ListNode(-1);
        ListNode *nh = temp;
        while(head){
            int k= head->val , c=1;
            while(head->next and (k == head->next->val)){
                head = head->next;
                c++;
            }
            if(c==1){
                temp->next = head;
                head = head->next;
                temp = temp->next;
                temp->next=NULL;
            }
            else head = head->next;
        }
        return nh->next;

    }
};