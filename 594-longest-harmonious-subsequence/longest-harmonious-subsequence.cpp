class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i =0 ; i<nums.size() ;i++){
            mp[nums[i]]++;
        }
        int maxi = 0;
        for(int i=0; i< nums.size();i++){
            if(mp[ nums[i] +1] > 0){
                maxi = max(maxi , mp[nums[i]] + mp[nums[i]+1]);
            }
            else if(mp[nums[i]-1] > 0){
                maxi = max(maxi , mp[nums[i]] + mp[nums[i]-1]);
            }
        }
        return maxi;
    }
};