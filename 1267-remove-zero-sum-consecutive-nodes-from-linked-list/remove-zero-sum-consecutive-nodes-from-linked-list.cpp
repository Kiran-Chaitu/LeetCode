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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> v;
        ListNode *t=head;
        int pc=0,nc=0,len=0,zc=0;
        while(t){
            len++;
            if(t->val > 0) pc++;
            else if(t->val == 0) zc++;
            else if(t->val < 0) nc++;
            v.push_back(t->val);
            t=t->next;
        }
        if(len==pc || len==nc) return head;
        if(len==zc) return NULL;
        int k=1;
        while(k){
           // for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
            //cout<<endl;
            k=0;
            int fi,li,ps=0;
            unordered_map<int,int> mp;
            for(int i=0;i<v.size();i++){
                if(v[i]==0){
                    k=1;
                    fi=i;
                    li=i;
                    break;
                }
                ps+=v[i];
                if(ps==0){
                    k=1;
                    li=i;
                    fi=0;
                    break;
                }
                if(mp.find(ps) ==mp.end() ) mp[ps]=i;
                else{
                    k=1;
                    li=i;
                    fi=mp[ps]+1;
                    break;
                }
                

            }
            if(k){
                v.erase(v.begin()+fi,v.begin()+li+1);
            }
            mp.clear();
        }
        if(!v.empty()){
            ListNode *nh = new ListNode(v[0]);
            ListNode *t=nh;
            for(int i=1;i<v.size();i++){
                 ListNode *nn = new ListNode(v[i]);
                 t->next = nn;
                 t = t->next;
            }
            return nh;
        }
        else return NULL;
    }
};