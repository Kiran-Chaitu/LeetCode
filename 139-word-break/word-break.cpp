class Solution {
public:
    bool start(int i,int n,string &s, map<string,int>&mp,vector<int>&dp){
        if (i>=n) return true;
        if (dp[i] != -1) return dp[i];
        bool ans = false;
        for (auto [word,val] : mp){
            if (word[0]==s[i]){
                int m = word.size();
                if (i+m<=n){
                    string sub = s.substr(i,m);
                    if (sub == word){
                        ans |= start(i+m,n,s,mp,dp);
                    }
                }
            }
        }
        return dp[i] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        map<string,int> mp;
        for (string i : wordDict) mp[i]++;
        vector<int> dp(n,-1);
        return start(0,n,s,mp,dp);
    }
};