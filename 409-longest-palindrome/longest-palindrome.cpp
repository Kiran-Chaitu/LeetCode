class Solution {
public:
    int longestPalindrome(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int o=0,es=0,os=0,om=0;
        if(mp.size()==1) return mp[s[0]];
        for(auto i:mp){
            if(i.second%2!=0){
                o++;
                om=max(om,i.second);
            }
        }
        for(auto i:mp){
            if(i.second%2==0) es+=i.second;
            else {
                if(i.second==om and o>=1){
                    os+=om;
                    o=0;
                }
                else os+=(i.second-1);
            }
        }
        return es+os;
    }
};