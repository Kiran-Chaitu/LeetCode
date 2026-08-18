class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;
        int n = s.size() , ans = 0 , l = 0,r = 0;
        while(r < n){
            mp[s[r]]++;
            while(mp.size() == 3){
                ans += n - r;
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            r++;
        }
        return ans;
    }
};