class Solution {
public:
    bool solver(int i ,vector<vector<int>> &dp ,vector<int> &nums, int target){
        if(target == 0) return true;
        if(i < 0){
            return target == 0;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        bool pick  = false;
        if(nums[i] <= target) pick = solver(i-1 , dp , nums, target - nums[i]);
        bool unpick  = solver(i-1 , dp , nums , target);
        return dp[i][target] = pick || unpick;
    } 
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp( n+1 , vector<int>(20001,-1));
        int sum=0;
        for(auto i:nums) sum+=i;
        if(sum & 1) return 0;
        int target = sum/2;
        return solver(n-1 , dp , nums , target);
        
    }
};