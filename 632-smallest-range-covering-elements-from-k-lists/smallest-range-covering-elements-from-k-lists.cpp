class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> v;
        int k = nums.size();
        for (int i=0; i<k; i++){
            for (int j=0; j<nums[i].size(); j++){
                v.push_back({nums[i][j], i});
            }
        }
        sort(begin(v), end(v));
        map<int,int> mp;
        int maxi = 1e6, mini = -1e6;
        vector<int> ans = {mini, maxi};
        int i = 0,j = 0;
        int n = v.size();
        while (j<n){
            mp[v[j].second]++;
            while (mp.size() == k){
                int low = v[i].first;
                int high = v[j].first;
                if (ans[1]-ans[0] > high - low){
                    ans[0] = low;
                    ans[1] = high;
                }
                if (mp[v[i].second] == 1) mp.erase(v[i].second);
                else mp[v[i].second]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};