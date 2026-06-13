class Solution {
public:
    int solver(int i, int j ,vector<vector<int>> &dp , vector<vector<int>> &grid){
        if(i<0 || j <0) return INT_MAX;
        if(i==0 and j ==0 ) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up  = solver(i-1,j,dp,grid);
        int left = solver(i,j-1,dp,grid);
        return dp[i][j] = grid[i][j] + min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return solver(m-1,n-1,dp,grid);
    }
};