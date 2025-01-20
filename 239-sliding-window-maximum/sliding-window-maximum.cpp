class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<k;i++){
            while(!dq.empty() and nums[i] > dq.back()) dq.pop_back();
            dq.push_back(nums[i]);
        }
        ans.push_back(dq.front());
        for(int i = k ;i<nums.size() ;i++){
            if( nums[i-k] == dq.front()) dq.pop_front();
            while(!dq.empty() and nums[i] > dq.back()) dq.pop_back();
            dq.push_back(nums[i]);
            ans.push_back(dq.front());
        }
        
        return ans;
    }
};