class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        for(int i=0;i<s.size();i++){
            int com=0;
            unordered_map<char,int> m;
            for(int j=i;j<s.size();j++){
                m[s[j]]++;
                if(m[s[j]]>1){
                    break;
                }
                com++;
            }
            if(com>l) l=com;
        }
        return l;
    }
};