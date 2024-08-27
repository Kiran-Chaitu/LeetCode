class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int mini = INT_MAX,n=nums.size();
        for(int i=0;i<n;i++){
            for(int j= i;j<n;j++){
                int ans=0;
                for(int a=i;a<=j;a++){
                    ans|=nums[a];
                }
                if(ans >= k ){
                    mini = min( mini, j-i+1);
                }
            }
        }
        return (mini!=INT_MAX)? mini:-1;
    }
};