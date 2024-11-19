class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        long long int ans=0,maxi=0;
        unordered_map<int,int> mp;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
            ans+=nums[i];
        }
        if(mp.size()==k) maxi = ans;
        for(int i=k;i<nums.size();i++){
            ans-=nums[i-k];
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]<=0){
                mp.erase(nums[i-k]);
            }
            ans+=nums[i];
            mp[nums[i]]++;
            if(mp.size()==k) maxi=max(maxi,ans);
        }
        return maxi;
    }
};