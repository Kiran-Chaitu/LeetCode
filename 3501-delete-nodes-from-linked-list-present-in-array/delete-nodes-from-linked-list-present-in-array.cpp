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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> mp;
        ListNode* temp = head;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        temp=head;
        while(head and mp[head->val]!=0){
            head = head->next;
        }
        ListNode* prev = head;
        if(head!=NULL) temp = head->next;
        while(temp){
            if(mp[temp->val]!=0){
                prev->next = temp->next;
                temp = temp->next;
            }
            else{
                prev =temp;
                temp=temp->next;
            }
            
        }
        return head;
    }
};