class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ios_base::sync_with_stdio(0);
        int l = 0 , r = 0 , maxi = 0;  
        unordered_map<int,int> mp;
        while(r < s.size()){
            mp[s[r]]++;
            while(mp[s[r]] > 1){
                mp[s[l++]]--;
            }
            maxi = max(maxi , r-l + 1);
            r++;
        }
        return maxi;
    }
};