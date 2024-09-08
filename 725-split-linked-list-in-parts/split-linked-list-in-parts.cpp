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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        ListNode *temp,*prev;
        temp=head;
        int c=0;
        vector <ListNode*> v;
        while(temp){
            temp=temp->next;
            c++;
        }
        temp = head;
        if(k>=c){
            while(k--){
                if(temp){
                    ListNode* nxt = temp;
                    v.push_back(temp);
                    temp = temp->next;
                    nxt->next = nullptr;
                }
                else v.push_back(nullptr);
            }
            return v;
        }
        int p=c/k,l=c%k;
        while(k--){
            v.push_back(temp);
            int x=p;
            if(l>0){
                x++;
                l--;
            }
            while(x-- and temp){
                prev = temp;
                temp = temp -> next;
            }
            prev->next=nullptr;
        }
        return v;
    }
};