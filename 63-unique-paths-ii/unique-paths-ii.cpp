class Solution {
public:
    int solver(int i,int j , vector<vector<int>> &dp, vector<vector<int>> &grid){
        if(i < 0 || j < 0) return 0;
        if(i==0 and j ==0 ) return 1;
        if(grid[i][j]) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = solver(i-1,j,dp, grid);
        int left = solver(i , j -1 , dp, grid);
        return dp[i][j] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]) return 0;
        int m = obstacleGrid.size() ,  n = obstacleGrid[0].size();
        vector<vector<int>> dp(m ,  vector<int>(n,-1));
        // return solver(m-1,n-1,dp,obstacleGrid);
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n ; j++){
                if(i == 0 and j == 0){
                    dp[i][j] = 1;
                }
                else if(obstacleGrid[i][j]){
                    dp[i][j] = 0;
                }else{
                    int up = 0, left = 0;
                    if(i-1>=0) up+=dp[i-1][j];
                    if(j-1>=0) left+=dp[i][j-1];
                    dp[i][j] = up + left;
                }
            } 
        }
        return dp[m-1][n-1];
    }
};