class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        for(int i=0;i<nums.size();i++){
            nums[i]=(nums[i] * nums[i]);
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};