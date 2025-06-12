#define ll long long

class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        vector<ll> ans;
        map<int,long long> mp;
        int n = nums.size();
        map<pair<long long,int> , int> cal;
        for(int i=0;i<n;i++){
            ll temp=-1;
            if(mp.find(nums[i]) != mp.end()){
                temp = mp[nums[i]];
            }
            mp[nums[i]] += freq[i];
            if(temp!=-1 and cal.find({temp , nums[i]}) != cal.end()){
                cal.erase({temp , nums[i]});
            }
            cal[{mp[nums[i]] , nums[i]}]=1;
            if(!cal.empty()) ans.push_back(cal.rbegin()->first.first);
            else ans.push_back(0);
        } 
        return ans;
    }
};