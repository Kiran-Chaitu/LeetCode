class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.size()==1) return 0;
        unordered_map<int,int> mp;
        int ans=0;
        if(k==0){
            for(int i=0;i<nums.size();i++){
                mp[nums[i]]++;
                if(mp[nums[i]]>1){
                    ans++;
                    mp[nums[i]]=INT_MIN;
                }
                if(mp[-(nums[i])]>0 and nums[i]!=0 and nums[i]<0 ){
                    mp[nums[i]]=0;
                    mp[-nums[i]]=0;
                    ans++;
                }
                
            }
            return ans;
        }
        set<int> st(nums.begin(),nums.end());
        nums.clear();
        nums.assign(st.begin(),st.end());
        for(auto i:nums) mp[i]=1;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i] - k)!=mp.end()) ans++;
        }
        return ans;
    }
};