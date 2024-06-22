class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int oc=0,i=0,j=0,ans=0,n=nums.size();
        unordered_map<int,int> mp;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0){
                oc++;
                mp[oc]=i;
            }
        }
        oc++;
        if(mp.size()!=1){
            mp[oc]=n;
            for(auto i:mp){
                if(i.first>=k and mp[i.first]!=n){
                    int a = (mp[i.first - k +1]) - (mp[i.first - k] +1)  +1;
                    int b = (mp[i.first+1] - 1) - (mp[i.first]) +1;
                    ans+=(a*b);
                }
            }
        }
        return ans;
    }
};