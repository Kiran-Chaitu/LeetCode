class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        map<int  , deque<pair<int,int>>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i][0]].push_back({i,0});
        }
        int val  = INT_MAX;
        vector<int> ans = {};
        while(true){
            auto mini = mp.begin();
            auto maxi = mp.rbegin();
            int diff = maxi->first - mini->first;
            int minI =mini->second[0].first ,  minJ = mini->second[0].second;
            if(diff < val){
                val = diff;
                ans = {mini->first , maxi->first};
            }
            if(minJ == nums[minI].size()-1){
                break;
            }
            int nextJ = minJ + 1;
            mp[mini->first].pop_front();
            mp[nums[minI][nextJ]].push_back({minI , nextJ});
            if(mp[nums[minI][minJ]].size() ==0) mp.erase(nums[minI][minJ]);
        }
        return ans;
    }
};