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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0,c=0;
        ListNode *rhead=NULL,*rt;
        ListNode *t1=l1,*t2=l2;
        while(t1 and t2){
            sum=t1->val + t2->val + c;
            ListNode* res= new ListNode((sum%10));
            c=sum/10;
            if(rhead==NULL){
               rhead=res;
               rt=rhead; 
            } 
            else{
                rt->next=res;
                rt=rt->next;
            }
            t1=t1->next;
            t2=t2->next;
        }
        if(t1!=NULL){
            while(t1){
                sum = t1 -> val + c;
                ListNode* res = new ListNode(sum%10);
                c=sum/10;
                if(rhead==NULL){
                    rhead=res;
                    rt=rhead; 
                } 
                else{
                    rt->next=res;
                    rt=rt->next;
                }
                t1=t1->next;
            }
            if(c!=0){
                ListNode* res=new ListNode(c);
                rt->next = res;
                rt=rt->next;
            }
        }
        else{
            while(t2){
                sum = t2 -> val + c;
                ListNode* res = new ListNode(sum%10);
                c=sum/10;
                if(rhead==NULL){
                    rhead=res;
                    rt=rhead; 
                } 
                else{
                    rt->next=res;
                    rt=rt->next;
                }
                t2=t2->next;
            }
            if(c!=0){
                ListNode* res=new ListNode(c);
                rt->next = res;
                rt=rt->next;
            }
        }
        return rhead;
    }
};