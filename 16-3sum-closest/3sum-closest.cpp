class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=INT_MAX , n = nums.size() , sol=-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if( abs(sum - target) < ans){
                    ans = abs(sum - target);
                    sol = sum;
                }
                if(sum >= target) k--;
                else j++;
            }
        }
        return sol;
    }

};