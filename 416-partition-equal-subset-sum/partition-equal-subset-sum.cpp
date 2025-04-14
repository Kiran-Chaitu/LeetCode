class Solution {
public:
    int solver(int i , vector<vector<int>> &dp , vector<int> &nums , int target, int sum , int total){
        if(i==nums.size() or sum >= target){
            return abs(2*sum - total);
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        return dp[i][sum] = min(
            solver(i+1 , dp , nums , target , sum+nums[i] , total),
            solver(i+1 , dp , nums , target , sum , total)
        );
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp( n+1 , vector<int>(20001,-1));
        int sum=0;
        for(auto i:nums) sum+=i;
        int target = ceil((double)(sum)/2);
        int k = solver(0 , dp , nums , target ,0 , sum );
        return k==0;
    }
};