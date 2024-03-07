class Solution {
public:
    bool isAnagram(string s, string t) {
        ios_base::sync_with_stdio(0);
        map<char,int> m;
        for(int i=0;i<s.size();i++) m[s[i]]++;
        for(int i=0;i<t.size();i++){
            m[t[i]]--;
            if(m[t[i]]<0) return 0;
        }
        for(auto i:m){
            if(i.second!=0) return 0;
        }
        return 1;
    }
};