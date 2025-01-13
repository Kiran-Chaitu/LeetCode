class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> mp;
        for(auto i:s) mp[i]++;
        int ans=0;
        for(auto i:mp){
            int k=i.second;
            if(k > 2) if(k&1) k = 1;else k=2;
            ans+=k;
        }
        return ans;
    }
};