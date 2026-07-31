class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26);
        for(auto i : word){
            mp[i - 'a']++;
        }
        sort(mp.begin() , mp.end() , [](int a , int b){
            return a > b;
        });
        int ans = 0;
        for(int i = 0; i < 26;i++){
            if(i < 8) ans += mp[i];
            else if(i < 16) ans+= mp[i] * 2;
            else if(i < 24) ans += mp[i] * 3;
            else ans += mp[i] * 4;
        }
        return ans;
    }
};