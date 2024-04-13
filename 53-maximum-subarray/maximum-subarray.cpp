class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Code written By ___Kiran__Chaitu___
        ios_base::sync_with_stdio(0);
        int gs=-100000,ms=-100000;
        for(int i=0;i<nums.size();i++){
            int sum=ms+nums[i];
            ms = max(sum,nums[i]);
            gs=max(gs,ms);
        }
        return gs;
    }
};