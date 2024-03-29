class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        long long ans=0,maxi=-1,l=0,r=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(maxi<nums[i]) maxi = nums[i];
        }
        int c=0;
        while(r<n){
            if(nums[r]==maxi) c++;
            while(c>=k){
                ans+=(n-r);
                if(nums[l]==maxi) c--;
                l++;
            }
            //cout<<c<<" "<<ans<<" "<<l<<" "<<r<<endl;
            r++;
        }
        return ans;
    }
};