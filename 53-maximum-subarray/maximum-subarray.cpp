class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        int cs=-100000,ts=-100000;
        for(int i=0;i<nums.size();i++){
            cs = max(cs+nums[i] , nums[i]);
            ts = max(cs , ts);
        }
        return ts;
    }
};