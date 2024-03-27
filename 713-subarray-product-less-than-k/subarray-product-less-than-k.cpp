class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        ios_base::sync_with_stdio(0);
        int l=0,r=0,p=1,c=0,n=nums.size();

        while(r<n){
            p*=nums[r];
            if(p>=k){
                c+=((r-l)*(r-l+1)/2);
                while(p>=k){
                    p/=nums[l];
                    l++;
                }
                if(l<r) c-=((r-l)*(r-l+1)/2);
            }
            r++;
        }
        if(p<k) c+=((r-l)*(r-l+1)/2);
        return c;
    }
};