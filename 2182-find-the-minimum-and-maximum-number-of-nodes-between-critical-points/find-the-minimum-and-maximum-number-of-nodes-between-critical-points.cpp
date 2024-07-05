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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int c=2,i=0,mini=INT_MAX,first=-1,curr=-1;
        ListNode *temp = head;
        while(temp -> next ->next ){
            if((temp->val < temp->next->val and temp->next->val > temp->next->next-> val)
                or (temp->val > temp->next->val and temp->next->val < temp->next->next->val)){
                    
                    if(first==-1){
                        first = c;
                    }
                    else{
                        if(curr==-1) mini = min(mini , c - first);
                        else    mini = min(mini , c - curr );
                        curr = c;
                    }
            }
            temp=temp->next;
            c++;
        }
        if(curr==-1) return {-1,-1};
        return {mini , curr - first};
    }
};