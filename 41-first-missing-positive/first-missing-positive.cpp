class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0) nums[i]=0;
        }
        sort(nums.begin(),nums.end());
        int flag=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                flag=0;
                break;
            }
        }
        if(flag) return 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] - nums[i-1] > 1) return nums[i-1]+1;
        }
        return nums[nums.size()-1]+1;
    }
};