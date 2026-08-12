class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = 0;
        unordered_map<int,int> mp;
        int l = 0;
        for(int i = 0; i < n;i++){
            mp[nums[i]]++;
            while(mp[nums[i]] > k){
                mp[nums[l++]]--;
            }
            maxi = max(maxi , i-l+1);
        }
        return maxi;
    }
};