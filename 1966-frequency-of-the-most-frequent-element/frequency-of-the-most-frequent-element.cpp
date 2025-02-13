class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long int sum =nums[0];
        int c=1, n =nums.size() , maxi =1;
        for(int i=1;i<n ; i++){
            if(nums[i] == nums[i-1]) c++;
            else c=1;
            maxi = max(maxi , c);
        }
        int l=0;
        for(int r=1;r<n;r++){
            long long int temp =(long long)((long long )(nums[r])* (long long)(r-l));
            while(temp - sum > k and l<r){
                sum-=nums[l++];
                temp =(long long)((long long )(nums[r])* (long long)(r-l));
            }
            sum+=nums[r];
            //cout<<"l = "<<l<<" r = "<<r<<endl;
            maxi = max(maxi , r-l+1);
        }
        return maxi;
    }
};