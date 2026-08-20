class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size() , l= 0 , r = 0 , sum = 0;
        while(r < n){
            sum += nums[r];
            while(sum >= target){
                ans = min(ans, r-l+1);
                // cout<<"ans:"<<ans<<endl;
                // cout<<"Sum :"<<sum<<endl;
                // cout<<r<<" "<<l<<" "<<endl;
                // cout<<endl;
                sum -= nums[l];
                l++;
            }
            
            r++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};