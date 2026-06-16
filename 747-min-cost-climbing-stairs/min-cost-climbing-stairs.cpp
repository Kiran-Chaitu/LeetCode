class Solution {
public:
    int solver(int n , vector<int> &dp , vector<int> &cost){
        // if(n < 0) return INT_MAX;
        if(n <= 1) return cost[n];
        if(dp[n]!=-1) return dp[n];
        int left = solver(n-1 , dp ,cost);
        int right = solver(n-2 , dp, cost);
        return dp[n] = cost[n] + min(left , right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1 , -1);
        cost.push_back(0);
        return solver(n, dp, cost);
        
    }
};