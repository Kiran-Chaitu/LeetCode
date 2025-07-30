class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int c = 1  ,maxi = *max_element(nums.begin() , nums.end()),ans = 1;
        // cout<<maxi<<endl;
        for(int i = 0 ; i < nums.size()-1;i++){
            if(nums[i] == nums[i+1] and nums[i] == maxi){
                c++;
                ans = max(ans , c);
            }
            else c=1;
        }
        return ans;
    }
};