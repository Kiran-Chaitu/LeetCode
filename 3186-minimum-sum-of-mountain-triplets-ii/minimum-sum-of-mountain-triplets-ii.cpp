class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n),suf(n);
        int ans = INT_MAX;
        for(int i =0 ; i < n; i++){
            pre[i] = ans;
            ans = min(ans, nums[i]);
        }
        ans = INT_MAX;
        for(int i=n-1;i>=0;i--){
            suf[i] = ans;
            ans = min(ans, nums[i]);
        }
        ans = INT_MAX;
        for(int i = 0; i < nums.size();i++){
            if(pre[i] < nums[i] and suf[i] < nums[i]){
                ans = min(ans, pre[i] + nums[i] + suf[i]);
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};