class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_map<char,int> mp;
        vector<char> v ={'a','e','i','o','u'};
        for(auto i:v) mp[i]++;
        int vc = 0;
        for(auto i : s){
            if(mp[i]) vc++;
        }
        if(vc==0) return false;
        return true;


    }
};