class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int l=0,r=0,pmin=-1,pmax=-1;

        while(r<nums.size()){
            int temp=nums[r];
            if(temp<minK || temp>maxK){
                l=r+1;
                pmin=-1;
                pmax=-1;
            }
            else{
                if(temp==minK) pmin=r;
                if(temp==maxK) pmax=r;
                //ans+=max(0,pmax-l+1);
                if(pmax<pmin){
                    if(pmax-l+1>0) ans+=pmax-l+1;
                }
                else{
                    if(pmin-l+1>0) ans+=pmin-l+1;
                }
            }  
            r++; 
        }

        return ans;
    }
};