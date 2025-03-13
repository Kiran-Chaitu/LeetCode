class Solution {
public:
    // memoization
    // int solver(int i , int j , string &s1, string &s2, vector<vector<int>> &dp){
    //     if(i==0){
    //         return j;
    //     } 
    //     if(j==0) return i;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s1[i-1] == s2[j-1]) return solver(i-1,j-1,s1,s2,dp);
    //     dp[i][j] =  1 + min(solver(i,j-1,s1,s2,dp) , min(solver(i-1,j,s1,s2,dp),
    //     solver(i-1,j-1,s1,s2,dp)));
    //     return dp[i][j];
    // }
    int minDistance(string word1, string word2) {
        // memoization
        // int n = word1.size() , m = word2.size();
        // vector<vector<int>> dp(n +1, vector<int>(m+1,-1));
        // return solver(n,m ,word1,word2,dp);

        // Tabulation
        int n = word1.size() ,m= word2.size();
        vector<vector<int>> dp(n+1 , vector<int>(m+1,-1));
        for(int i=0;i<=n;i++) dp[i][0] = i;
        for(int i=0;i<=m;i++) dp[0][i] = i;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                // cout<<dp[i][j]<<" ";
                if(word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = 1 + min(dp[i-1][j] , min(dp[i-1][j-1] , dp[i][j-1]));
                }
            }
            // cout<<endl;
        }
        return dp[n][m];
    }
};