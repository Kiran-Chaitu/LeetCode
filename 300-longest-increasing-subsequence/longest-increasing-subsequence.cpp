class Solution {
public:
    int lengthOfLIS(vector<int>& nums){
        int n = nums.size() , c=0;
        vector<int> dp(n);
        for(int i=1;i<n;i++){
            int maxi = 0 ,c=0;
            for(int j=i;j>=0;j--){
                if(nums[j] < nums[i]){
                    c++;
                    maxi = max(maxi , dp[j]);
                }
            }
            if(c) dp[i] = 1 + maxi;
        }
        int maxi = 0;
        for(int i=1;i<n;i++){
            maxi = max(dp[i] , maxi);
            // cout<<dp[i]<<" ";
        }
        return maxi+1;
    }
};