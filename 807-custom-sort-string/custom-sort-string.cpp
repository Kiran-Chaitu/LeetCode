class Solution {
public:
    string customSortString(string order, string s) {
        ios_base::sync_with_stdio(0);
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        sort(s.begin(),s.end());
        string ns="";
        for(int i=0;i<order.size();i++){
            while(mp[order[i]] > 0){
                ns+=order[i];
                mp[order[i]]--;
            }
        }
        for(auto i : mp){
            while(i.second > 0){
                ns+=i.first;
                i.second--;
            } 
        }
        return ns;

    }
};