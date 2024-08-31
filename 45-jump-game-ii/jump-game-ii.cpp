class Solution {
public:
    int jump(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int n=nums.size();
        if(n==1) return 0;
        if(nums[0] >= n-1) return 1;
        int i=0,c=0;
        while(i<n){
            int k=nums[i],maxi=INT_MIN,temp;
            if(i>=n-1) return c;
            for(int j=i+1;j<=i+k;j++){
                if(nums[j]+j > maxi){
                    maxi = nums[j]+j;
                    temp=j;
                }
            }
            i=temp;
            c++;
            if(nums[i] + i>=n-1) return c+1;
        }
        return -1;
    }
};