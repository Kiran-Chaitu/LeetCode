class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i:nums) mp[i]=1;
        int maxi =0;
        for(auto i : nums){
            if(mp[i]==1){
                int c=1 , j=i-1;
                while(mp[j]==1){
                    c++;
                    mp[j--] = -1;
                }
                j=i+1;
                while(mp[j]==1){
                    c++;
                    mp[j++]=-1;
                }
                maxi = max(maxi,c);
            }
        }
        return maxi;
    }
};