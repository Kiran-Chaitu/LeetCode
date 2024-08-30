class Solution {
public:
    bool canJump(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int n=nums.size(),i=0,temp;
        if(n==1) return true;
        if(nums[0]==0) return false;
        if(nums[0] >= n) return true;
        while(i<n){
            int k=nums[i],maxi=INT_MIN;
            if(k==0) return false;
            if(i >= n-1 ) return true;
            for(int j=i+1;j<=i+k;j++){
                if(maxi < (j+nums[j])){
                    maxi = j+nums[j];
                    temp=j;
                }
            }
            i=temp;
            if(i + nums[i]>=n-1) return true;
        }
        return false;
    }
};