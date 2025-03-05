class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size() , m = obstacleGrid[0].size();
        // if(n==1 and m==1) return 1;
        if(obstacleGrid[0][0]) return 0;
        vector<vector<long long >> dp( n , vector<long long> (m,0));
        for(int i=0;i<n;i++){ if(!obstacleGrid[i][0]) dp[i][0]=1;
        else break;
        }
        for(int i=0;i<m;i++){ if(!obstacleGrid[0][i]) dp[0][i]=1;else break;}
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(!obstacleGrid[i][j]) dp[i][j] += dp[i-1][j] + dp[i][j-1];
                else dp[i][j]=0;
            }
        }
        return dp[n-1][m-1];
    }
};