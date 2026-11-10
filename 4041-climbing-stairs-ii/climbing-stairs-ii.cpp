class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        long long int mod = 1e9;
        vector<long long int> dp(n+1 , mod);
        dp[0] =0;
        for(int i=1;i<=costs.size();i++){
            if(i-1 >= 0) dp[i] = min(dp[i] , dp[i-1] + costs[i-1] + 1);
            if(i-2 >=0) dp[i] = min(dp[i] , dp[i-2] + costs[i-1] + 4);
            if(i-3 >=0) dp[i] = min(dp[i] , dp[i-3] + costs[i-1]  +9);
        }
        return dp[n];
    }
};