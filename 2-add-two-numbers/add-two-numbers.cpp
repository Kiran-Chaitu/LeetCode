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
ListNode* insert(ListNode* head,int res){
    
    ListNode *nn = new ListNode(res);
    ListNode *temp=head;
     if(head==NULL){
         head=nn;
     }
     else{
         while(temp->next!=NULL){
             temp=temp->next;
         }
         temp->next=nn;
     }
     return head;
 }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
     ListNode* res=NULL;
   ListNode* t1=l1;
   ListNode* t2=l2;
    while(l1!=NULL && l2!=NULL){
        int data = l1->val + l2->val +carry;
        l1=l1->next;
        l2=l2->next;
        res=insert(res,data%10);
        carry=data/10; 
    }
    
    while(l1!=NULL){
        int data=l1->val+carry;
        res=insert(res,data%10);
        carry=data/10;
        l1=l1->next;
    }
    while(l2!=NULL){
        int data=l2->val+carry;
        res=insert(res,data%10);
        carry=data/10;
        l2=l2->next;
    }
    if(carry!=0){
        res=insert(res,carry);
    }
    return res;
    }
};