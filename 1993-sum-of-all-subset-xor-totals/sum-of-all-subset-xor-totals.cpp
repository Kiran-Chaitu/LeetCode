class Solution {
public:
    int sum=0;
    void solver(vector<int> &nums , int ind ,int n ,int ans){
        if(ind == n){
            sum+=ans;
            // cout<<ans<<" "<<sum<<endl;
            return;
        }
        solver(nums , ind + 1 , n , ans ^ nums[ind]);
        solver(nums , ind + 1 , n , ans);
    }
    int subsetXORSum(vector<int>& nums) {
        solver(nums , 0 , nums.size() , 0);
        return sum;
    }
};