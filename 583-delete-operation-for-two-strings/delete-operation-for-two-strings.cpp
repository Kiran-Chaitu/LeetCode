class Solution {
public:
    int minDistance(string text1, string text2) {
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
        return n+m - 2 * dp[0][0];
    }
};