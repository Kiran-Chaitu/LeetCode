class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int> ans;
        vector<pair<int,int>> temp(mp.begin(),mp.end());
        sort(temp.begin(),temp.end(),[](pair<int,int> &a , pair<int,int> &b){
            return a.second > b.second;
        });
        for(auto i:temp){
            if(k==0) break;
            ans.push_back(i.first); 
            k--;
        }
        return ans;
    }
};