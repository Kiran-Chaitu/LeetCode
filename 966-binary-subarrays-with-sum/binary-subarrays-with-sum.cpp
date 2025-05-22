class Solution {
public:
    int solver(vector<int> &nums , int k){
        int c=0;
        if(k<0) return 0;
        int l= 0 , r = 0, n = nums.size() , sum =0;
        while(r < n){
            sum+=nums[r];
            while(sum > k){
                sum-=nums[l++];
            }
            c += (r-l+1);
            r++;
        }
        return c;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        ios_base::sync_with_stdio(0);
        return solver(nums,goal) - solver(nums , goal-1);
    }
};