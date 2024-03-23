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
    void reorderList(ListNode* head) {
        ListNode *temp = head;
        stack<ListNode *> st;
        int c=0;
        while(temp){
            c++;
            st.push(temp);
            temp = temp->next;
        }
        if(c<=2) return;
        temp = head;
        ListNode *np = temp->next , *lp=st.top();
       while(np!=lp and temp!=lp){
            temp->next = lp;
            lp->next = np;
            temp = np;
            np=np->next;
            st.pop();
            lp = st.top();
        } 
        lp->next=NULL;
    }
};