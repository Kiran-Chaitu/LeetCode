class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size() , ans =0;
        sort(nums.begin() , nums.end());
        for(int i = n-1 ; i >= 2; i-- ){
            if(nums[i-1] + nums[i-2] > nums[i]){
                ans = max(ans , nums[i] + nums[i-1] + nums[i-2]);
            }
        }
        return ans;
    }
};