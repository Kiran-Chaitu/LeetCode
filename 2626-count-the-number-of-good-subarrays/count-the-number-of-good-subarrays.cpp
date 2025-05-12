class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0, n = nums.size(), l = 0 , r = 0 , pairs =0;
        unordered_map<int,int> mp;
        while(r<n){
            mp[nums[r]]++;
            if(mp[nums[r]] > 0){
                pairs += mp[nums[r]]-1;
            }
            // cout<<" l = "<<l<<" r = "<<r<<" pairs = "<<pairs<<endl;
            while(l < r and  pairs >= k){
                ans += (n - r );
                pairs -= (mp[nums[l]] - 1);
                // cout<<" l = "<<l<<" r = "<<r<<" InPairs = "<<pairs <<" ans = "<<ans<<endl;
                mp[nums[l]]--;
                l++;
            }
            // cout<<" ans = "<<ans<<endl;
            r++;
        }
        return ans;

    }
};