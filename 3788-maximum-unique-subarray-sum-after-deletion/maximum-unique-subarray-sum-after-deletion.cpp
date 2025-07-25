class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int,int> mp;
        int s=0 , maxi =INT_MIN;
        for(auto i:nums){
            mp[i]=i;
            if(maxi < i) maxi = i;
        }
        for(auto i:mp) if(i.first >0) s+=i.first;
        return (s!=0 and s > maxi) ? s: maxi;
    }
};