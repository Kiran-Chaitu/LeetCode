class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int> mp;
        int n = word.size();
        for(int i = 0; i< n ; i++){
            if(word[i] >='a' and word[i]<='z'){
                mp[word[i]] = i;
            }else{
                if(mp.find(word[i]) == mp.end()){
                    mp[word[i]]=  i;
                }
            }
        }
        int c = 0;
        for(auto i : mp){
            char ch = i.first;
            if(mp.find(ch - 32)!=mp.end() and mp[ch] < mp[ch-32]) c++;
        }
        return c;
    }
};