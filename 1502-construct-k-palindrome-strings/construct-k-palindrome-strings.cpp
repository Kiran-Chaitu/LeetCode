class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.size()) return false;
        unordered_map<char,int> mp;
        for(auto i:s) mp[i]++;
        int c=0;
        for(auto i:mp){
            if(i.second & 1) c++;
        }
        if(c>k)return false;
        return true;
    }
};