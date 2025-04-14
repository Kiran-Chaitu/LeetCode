class Solution {
public:
    bool solver(int i , vector<vector<int>> &dp , vector<int> &nums , int target, int sum){
        if(i>=nums.size() or sum > target){
            return false;
        }
        if(sum==target) return true;
        if(dp[i][sum]!=-1) return dp[i][sum];
        return dp[i][sum] = solver(i+1 , dp , nums , target , sum+nums[i]) ||
            solver(i+1 , dp , nums , target , sum);
        
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp( n+1 , vector<int>(20001,-1));
        int sum=0;
        for(auto i:nums) sum+=i;
        if(sum & 1) return 0;
        int target = sum/2;
        return solver(0 , dp , nums , target ,0);
        
    }
};