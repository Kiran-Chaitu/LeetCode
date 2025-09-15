class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n = text.size()  , ans =0  , temp =1;
        unordered_map<char,int> mp;
        int i =0 ;
        for(auto i: brokenLetters) mp[i]=1;
        while(i < n){
            temp =1;
            while(i < n and text[i]!=' '){
                if(mp.find(text[i])!=mp.end()) temp = 0;
                i++;
            }
            if(temp) ans++;
            i++;
        }
        return ans;
    }
};