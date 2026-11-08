class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char> mp;
        unordered_map<char,string> up;
        string ns = "";
        int p = 0;
        for(int j = 0; j < s.size();j++){
            if(p >= pattern.size()) return false;
            if(s[j] == ' ' || j == s.size()-1){
                if(j == s.size()-1) ns+=s[j];
                if(mp.find(ns)!=mp.end()){
                    if(pattern[p]!=mp[ns]) return false;
                }else{
                    mp[ns] = pattern[p];
                }
                if(up.find(pattern[p])!=up.end()){
                    if(up[pattern[p]]!=ns) return false;
                }else{
                    up[pattern[p]] = ns;
                }
                ns = "";
                p++;
            }
            else ns += s[j];
        }
        return p == pattern.size();
    }
};