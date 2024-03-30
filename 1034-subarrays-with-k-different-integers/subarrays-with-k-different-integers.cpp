class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int l=0,r=0,ans=0,n=nums.size();
        while(r<n){
            mp[nums[r]]++;
            while(l<=r and mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]<=0) mp.erase(nums[l]);
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        mp.clear();
        int a = ans;
        l=0,r=0,ans=0,n=nums.size();
        while(r<n){
            mp[nums[r]]++;
            while(l<=r and mp.size()>k-1){
                mp[nums[l]]--;
                if(mp[nums[l]]<=0) mp.erase(nums[l]);
                l++;
            }
            ans+=(r-l)+1;
            r++;
        }
        int b = ans;
        return a-b;
    }
};