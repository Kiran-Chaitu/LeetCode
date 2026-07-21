class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0 , sum = 0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(auto i : nums){
            sum+=i;
            int rem = sum%k;
            if(rem < 0) rem+=k;
            if(mp.find(rem)!=mp.end()){
                ans+=mp[rem];
                mp[rem]++;
            }else mp[rem]=1;
        }
        return ans;
    }
};