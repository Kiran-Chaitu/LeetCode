class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        long long int c=0,sum=0,temp=0,n=nums.size();
        for(auto i:nums) sum+=i;
        for(int i=0;i<n-1;i++){
            temp+=nums[i];
            if(temp >= (sum - temp)) c++;
        }
        return c;
    }
};