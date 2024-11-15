class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> sf(n,INT_MIN),pf(n,INT_MIN);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and nums[st.top()] <= nums[i]) st.pop();
            if(!st.empty()) sf[i]=nums[st.top()];
            st.push(i);
        }
        for(int i=0;i<n;i++){
            while(!st.empty() and nums[st.top()] >= nums[i]) st.pop();
            if(!st.empty()) pf[i] = nums[st.top()];
            st.push(i);
        }
        for(int i=0;i<n;i++){
            if(pf[i]!=INT_MIN and sf[i]!=INT_MIN) return true;
        }
        return false;
    }
};