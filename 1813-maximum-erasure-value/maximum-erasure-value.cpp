class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum =0 , l = 0 , n = nums.size() ,r =0,t=0;
        unordered_map<int,int> mp;
        while(r < n){
            while(r < n and mp[nums[r]] !=1){
                t+= nums[r];
                // cout<<t<<" ";
                mp[nums[r++]]=1;
                sum = max(sum , t);
            }
            if(r>= n) break;
            // cout<<endl;
            while(l < r and mp[nums[r]] == 1){
                t-=nums[l];
                // cout<<t<<" ";
                mp.erase(nums[l++]);
            }
            // cout<<endl;
            sum = max(sum , t);
        }
        return sum;
    }
};