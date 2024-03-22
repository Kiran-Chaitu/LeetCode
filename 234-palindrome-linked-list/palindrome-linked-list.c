/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode node;
bool isPalindrome(struct ListNode* head){
    node *slow = head;
    node *fast = head;
    while (fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    node *temp=NULL;
    while(slow){
        node *p=slow->next;
        slow->next=temp;
        temp=slow;
        slow=p;
    }
    while(temp){
        if(temp->val!=head->val) return 0;
        temp=temp->next;
        head=head->next;
    }
    return 1;
}