class Solution {
public:
    int solver(int n , vector<int> &dp , vector<int> &cost){
        if(n<0) return INT_MAX;
        if(n<=1) return 0;
        if(dp[n]!=-1) return dp[n];
        int left =cost[n-1] +  solver(n-1 , dp, cost);
        int right =cost[n-2] +  solver(n-2 , dp  ,cost);
        dp[n] = min(left ,right);
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1 , -1);
        return solver(n , dp ,cost);
        // return 10;
    }
};