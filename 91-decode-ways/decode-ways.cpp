class Solution {
public:
    bool isValid(string s){
        if(s >="10" and s<="26") return true;
        return false;
    }
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int n = s.size();
        if(n == 1) return 1;
        vector<int> dp(n+1);
        if(s[n-1] != '0'){
            dp[n-1] = 1;
        }
        if(isValid(s.substr(n-2,2))) dp[n]=1;
        for(int i = n - 2; i >= 0 ; i--){
            if( s[i]!='0' ) dp[i]+=dp[i+1];
            else{
                string s1 ="", s2="";
                if(i > 0 ) s1+=s.substr(i-1,2);
                s2+=s.substr(i,2);
                if(!(isValid(s1)) and !(isValid(s2))) return 0;
            }
            string temp = s.substr(i,2);
            if(isValid(temp)){
                dp[i]+=dp[i+2];
            }
        }
        return dp[0];
    }
};