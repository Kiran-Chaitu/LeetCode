class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        unordered_map<int,int> mp;
        int l=0,r=0,maxi=INT_MIN;
        while(r<nums.size()){
            mp[nums[r]]++;
            while(mp[nums[r]] >k){
                mp[nums[l]]--;
                l++;
            }
            if((r-l+1) > maxi) maxi = r-l+1;
            //maxi = max(maxi,r-l+1);
            r++;
            
        }
        return maxi;
    }
};