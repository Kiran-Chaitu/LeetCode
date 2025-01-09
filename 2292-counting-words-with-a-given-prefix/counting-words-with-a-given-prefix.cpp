class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        for(auto i:words){
            if(i.rfind(pref,0) == 0) ans++;
        }
        return ans;
    }
};