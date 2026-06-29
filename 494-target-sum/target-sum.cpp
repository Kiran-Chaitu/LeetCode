class Solution {
public:
    int dfs(int i ,int target , vector<vector<int>> &dp , vector<int> &nums ){
        if(i  < 0){
            if(target == 0) return 1;
            return 0;
        }
        // if(dp[i][target]!=-1) return dp[i][target];
        int left = dfs(i-1 , target + nums[i] , dp , nums);
        int right = dfs(i-1 , target - nums[i] , dp ,nums);
        return left + right;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(1001,-1));
        return dfs(n-1 , target ,dp ,nums );
    }
};