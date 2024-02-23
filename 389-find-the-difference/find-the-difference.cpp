class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.size()==0) return t[0];
        unordered_map<char,int> m1,m2;
        for(int i=0;i<s.size();i++) m1[s[i]]++;
        for(int i=0;i<t.size();i++) m2[t[i]]++;
        for(int i=0;i<t.size();i++){
            if(m1[t[i]] < m2[t[i]]) return t[i];
        }
        return 'k';
    }
};