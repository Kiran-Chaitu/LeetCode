class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int tot = pow(2 , k) , n = s.size();
        map<string,int> mp;
        for(int i =0 ; i <= n-k ; i++){
            string temp="";
            for(int j=i;j<=i+k-1;j++){
                temp+=s[j];
            }
            mp[temp]=1;
        }
        return mp.size()==tot;
    }
};