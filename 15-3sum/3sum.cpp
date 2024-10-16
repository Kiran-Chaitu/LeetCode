class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        set<vector<int>> temp;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            int x=-(nums[i]);
            int j=i+1,k=n-1;
            while(j<k){
                int sum = nums[j] + nums[k];
                if(sum==x){  temp.insert({-x,nums[j++],nums[k--]});}
                else if(sum > x)    k--;
                else j++;
                // while( j < k and nums[j]==nums[j+1] )   j++;
                // while( k > j and nums[k]==nums[k-1] )   k--;
            }
        }
        for(auto i:temp) v.push_back(i);
        return v;
    }
};