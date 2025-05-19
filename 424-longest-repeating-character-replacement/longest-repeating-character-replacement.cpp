class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int ans =0 , maxi =0 , n = s.size(), l= 0 , r=0;
        while(r<n){
            mp[s[r]]++;
            maxi = max(maxi , mp[s[r]]);
            while(( r-l+1) - maxi > k){
                mp[s[l++]]--;
            }
            ans = max(ans , r-l+1);
            r++;
        }
        return ans;

    }
};