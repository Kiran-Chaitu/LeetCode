class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size() ;
        vector<vector<bool>> dp(n , vector<bool>(n,false));
        for(int i=0;i<n;i++) dp[i][i] = true;
        int ind=0 , l = 1;
        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                ind =i+1;
                l=2;
            }
        }
        for(int i=2;i<n;i++){
            for(int j=0;j<=n-i;j++){
                if(s[i+j]==s[j] and (dp[j+1][i+j-1])){
                    dp[j][i+j] = true;
                    if(l < i+1){
                        l = i+1;
                        ind = i+j;
                    }
                    // cout<<l<<" "<<ind<<endl;
                    // cout<<(j)<<" "<<i+j<<endl;
                }
            }
            // cout<<endl;
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<l<<" "<<ind<<endl;
        string ans="";
        while(l-- ) ans+=s[ind--];
        return ans;
    }
};