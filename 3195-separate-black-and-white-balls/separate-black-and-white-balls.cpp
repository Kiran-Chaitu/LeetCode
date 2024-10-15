class Solution {
public:
    long long minimumSteps(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        long long int ans=0,c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') c++;
            else ans+=c;
        }
        return ans;
    }
};