class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxi= 0,c=0,n=nums.size();
        unordered_map<int,int> mp;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0) c--;
            else c++;
            if(mp.find(c)!=mp.end()) maxi = max(maxi , i - mp[c]);
            else mp[c]=i;
        }
        return maxi;
    }
};