class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(),maxi = 0;
        vector<int> dp(n+1,0);
        map<string,int> mp;
        for (string i : wordDict){
            mp[i]++;
            int m = i.size();
            maxi = max(maxi,m);
        }
        dp[0] = 1;
        for (int i=1; i<=n; i++){
            for (int j=i; j>max(i-maxi,0); j--){
                string sub = s.substr(j-1,i-j+1);
                if (mp.find(sub) == mp.end()) continue;
                if (dp[j-1]==1) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
};