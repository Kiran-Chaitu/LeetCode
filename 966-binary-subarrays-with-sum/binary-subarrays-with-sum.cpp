class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        ios_base::sync_with_stdio(0);
        int c=0;
        if(goal==0){
            int l=0,i=0;
            while(i<nums.size()){
                if(nums[i]==0) l++;
                else{
                    c+=(l*(l+1))/2;
                    l=0;
                }
                i++;
            }
            if(nums[nums.size()-1]==0)  c+=(l*(l+1))/2;
            return c;
        }
        int sum=0,ps=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            ps+=nums[i];
            if(nums[i]==0) mp[ps]++;
            if(ps==goal){
                c+=(1+mp[0]);
            } 
            else if(ps > goal){
                c+=(mp[ps - goal] + 1);
            }
        }
        return c;
    }
};