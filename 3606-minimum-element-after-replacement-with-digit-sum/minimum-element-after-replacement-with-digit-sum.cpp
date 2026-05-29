class Solution {
public:
    long long int  sums(int n){
        long long int sum=0;
        while(n){
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int temp = sums(nums[i]);
            mini = min(mini,temp);
        }
        return mini;
    }
};