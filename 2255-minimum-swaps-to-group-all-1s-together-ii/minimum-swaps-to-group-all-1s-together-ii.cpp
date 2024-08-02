class Solution {
public:
    int minSwaps(vector<int>& nums) {
        long long int size = 0 , ans = 0 , n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1) size++;
        }
        for(int i=0;i<size;i++){
            if(nums[i]==0) ans++;
        }
        long long int temp=ans;
        for(int i=0;i<n;i++){
            if(nums[i]==0) temp--;
            if(nums[(i+size)%n]==0) temp++;
            if(ans > temp) ans = temp;
        }
        return ans;
    }
};