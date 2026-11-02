class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(),sum=0;
        if(n&1){
            int mid = n/2;
            for(int i= 0;i < n;i++){
                sum += abs(nums[i] - nums[mid]);
            }
        }else{
            int mid = (nums[n/2] + nums[(n/2)-1])/2;
            for(int i=0;i<n;i++){
                sum += abs(mid - nums[i]);
            }
        }
        return sum;
    }
};