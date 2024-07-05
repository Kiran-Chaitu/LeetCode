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
        unordered_map<int,int> mp;
        int c=2,i=0,mini=INT_MAX;
        ListNode *temp = head;
        while(temp -> next ->next ){
            if((temp->val < temp->next->val and temp->next->val > temp->next->next-> val)
                or (temp->val > temp->next->val and temp->next->val < temp->next->next->val)){
                    i++;
                    mp[i]=c;
                    if(mp.size()>=2){
                        mini = min(mini , mp[i] - mp[i-1]);
                    }
            }
            temp=temp->next;
            c++;
        }
        if(mp.size()<2) return {-1,-1};
        int n=mp.size();
        return {mini , mp[n] - mp[1]};
    }
};