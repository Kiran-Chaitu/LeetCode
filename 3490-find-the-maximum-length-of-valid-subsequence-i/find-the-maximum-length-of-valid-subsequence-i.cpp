class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even = 0 , odd = 0 ;
        for(int i: nums) if(i&1) odd++; else even++;
        int n = nums.size() , c = 0;
        for(int i=0;i<n-1;i++){
            if((nums[i]%2==0 and nums[i+1]%2!=0) || (nums[i]%2!=0 and nums[i+1]%2==0)) c++;
        }
        if(c> 0 ) c++;
        return max(c , max(even , odd));
    }
};