class Solution {
public:
    // int solver(int i, int j, string &s1, string &s2 , vector<vector<int>> &dp){
    //     if(i >= s1.size() || j >= s2.size()) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s1[i] == s2[j]){
    //         return 1 + solver(i+1,j+1 , s1,s2 , dp);
    //     }
    //     int left = solver(i+1,j,s1,s2,dp) , right = solver(i,j+1,s1,s2,dp);
    //     return dp[i][j] = max(left,right);
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size() , m  = text2.size();
        vector<vector<int>> dp( n+1 , vector<int>(m+1 , 0));
        // return solver(0,0,text1,text2,dp);
        for(int i = n-1 ;i >=0;i--){
            for(int j = m-1;j>=0;j--){
                if(text1[i]==text2[j]){
                    dp[i][j] = 1+ dp[i+1][j+1];
                    continue;
                }
                int left = dp[i+1][j] ,  right = dp[i][j+1];
                dp[i][j] = max(left, right);
            }
        }
        return dp[0][0];
    }
};