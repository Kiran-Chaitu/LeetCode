class Solution {
public:
    bool check(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int n=nums.size(),j=-1;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                j=i+1;
            }
        }
        if(j==-1)   return true;
        reverse(nums.begin(),nums.begin()+j);
        reverse(nums.begin()+j,nums.end());
        reverse(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1])   return false;
        }
        return true;
    }
};