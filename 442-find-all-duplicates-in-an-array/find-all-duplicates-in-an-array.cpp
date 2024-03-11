class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        vector<int> v;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]] != -1) mp[nums[i]]++;
            if(mp[nums[i]] >1){
                v.push_back(nums[i]);
                mp[nums[i]] = -1;
            } 
        }
        return v;
    }
};