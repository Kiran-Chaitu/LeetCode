class Solution {
private:
    int ans=0,maxb;
    void solver(vector<int> nums,int ind,int n,int bor){
        if(ind>=n){
            if(bor ==maxb)  ans++;
            return;
        }
        solver(nums,ind+1,n,bor | nums[ind]);
        solver(nums,ind+1,n,bor);
    }
public:
    int countMaxOrSubsets(vector<int>& nums){
        sort(nums.begin(),nums.end());
        int temp=0;
        for(int i:nums) maxb|=i;
        solver(nums,0,nums.size(),0);
        return ans;
    }
};