class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size() , m = word2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1));
        for(int i=0;i<=n;i++){
            dp[i][0] = i;
            //cout<<dp[i][0]<<" ";
        }
        //cout<<endl;
        for(int i=0;i<=m;i++){
            dp[0][i]=i;
            //cout<<dp[0][i]<<" ";
        }
        //cout<<endl;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                //cout<<dp[i][j]<<" ";
                if(word1[i-1]== word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] =1 + min( dp[i-1][j-1] , min(dp[i-1][j] , dp[i][j-1]) );
                }
                
            }
            //cout<<endl;
        }
        return dp[n][m];
    }
};