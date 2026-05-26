class Solution {
public:
    int minimumSum(vector<int>& nums) {
        map<int,int> pre,suf;
        int ans = INT_MAX;
        for(auto i  : nums) suf[i]++;
        for(int i = 0; i < nums.size();i++){
            suf[nums[i]]--;
            if(suf[nums[i]] <= 0) suf.erase(nums[i]);
            if(!(pre.empty()) and !(suf.empty())){
                int left = pre.begin()->first , right = suf.begin()->first;
                if(left < nums[i] and right < nums[i])    ans = min(ans, left + nums[i] + right);
            }
            pre[nums[i]]++;
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};