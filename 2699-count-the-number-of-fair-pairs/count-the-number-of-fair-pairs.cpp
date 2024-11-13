class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long int ans=0,n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            int maxi = upper - nums[i], mini = lower - nums[i];
            auto l = lower_bound(nums.begin()+i+1,nums.end(),mini);
            auto r = upper_bound(nums.begin()+i+1,nums.end(),maxi);
            ans+=(r-l);
        } 
        return ans;
       
    }
};