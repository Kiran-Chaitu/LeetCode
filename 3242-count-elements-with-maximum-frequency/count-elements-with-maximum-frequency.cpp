class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        unordered_map<int,int> mp;
        for(auto i : nums){
            mp[i]++;
        }
        int mxf=-1,c=0;
        for(auto i : mp){
            if(i.second>mxf){
                mxf = i.second;
                c = i.second;
            }
            else if(i.second == mxf){
                c+=i.second;
            }
        }
        return c;
    }
};