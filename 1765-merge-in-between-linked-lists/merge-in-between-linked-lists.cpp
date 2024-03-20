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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ios_base::sync_with_stdio(0);
        ListNode *t1=list1,*t2=list1,*temp=list1;
        int c=0;
        while(temp){
            if(c==a-1){
                t1=temp;
            }
            if(c==b){
                t2=temp->next;
                break;
            }
            temp=temp->next; 
            c++;
        }
        t1->next = list2;
        while(list2->next!=NULL){
            list2= list2->next;
        }
        list2->next = t2;
        return list1;
    }
};