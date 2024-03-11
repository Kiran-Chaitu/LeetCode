class Solution {
public:
    string customSortString(string order, string s) {
        ios_base::sync_with_stdio(0);
        unordered_map<char,int> mp1,mp2;
        for(int i=0;i<order.size();i++){
            mp1[order[i]]++;
        }
        for(int i=0;i<s.size();i++){
            mp2[s[i]]++;
        }
        sort(s.begin(),s.end());
        string ns="";
        for(int i=0;i<order.size();i++){
            while(mp2[order[i]] > 0){
                ns+=order[i];
                mp2[order[i]]--;
            }
        }
        for(auto i : mp2){
            while(i.second > 0){
                ns+=i.first;
                i.second--;
            } 
        }
        return ns;

    }
};