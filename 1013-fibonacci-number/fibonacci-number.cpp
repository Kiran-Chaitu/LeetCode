class Solution {
public:
    int fib(int n , vector<int> &dp){
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        int left = fib(n-1 ,dp);
        int right = fib(n-2 , dp);
        dp[n] = left + right;
        return dp[n];
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return fib(n,dp);
    }
};