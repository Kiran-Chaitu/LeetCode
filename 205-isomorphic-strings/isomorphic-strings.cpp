class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char,unordered_set<char>> mp , tp;
        for(int i = 0; i < n; i++){
            mp[s[i]].insert(t[i]);
        }
        for(int i = 0; i < n; i++){
            tp[t[i]].insert(s[i]);
        }
        for(auto i : mp){
            if(i.second.size() > 1) return false;
        }
        for(auto i : tp){
            if(i.second.size() > 1) return false;
        }
        return true;
    }
};