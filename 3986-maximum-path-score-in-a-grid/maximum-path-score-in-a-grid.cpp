class Solution {
public:
    int dfs(int i , int j , int k , int n, int m , vector<vector<vector<int>>> &dp ,
           vector<vector<int>> &grid
           ){
        if(i >= n || j >= m || k <0) return INT_MIN;
        int c=0;
        if(grid[i][j]) c++;
        if(i == n-1 and j == m-1){
            if(c > k) return INT_MIN;
            return grid[i][j];
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];
        int r = dfs(i ,j +1 , k-c , n,m,dp,grid);
        int d =dfs(i+1 , j , k-c , n , m,dp,grid);
        int maxi = max(r,d);
        if(maxi == INT_MIN) dp[i][j][k] = INT_MIN;
        else dp[i][j][k] = maxi + grid[i][j];
        return dp[i][j][k];
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<vector<int>>> dp( n , vector<vector<int>>( m , vector<int>(k+1,-1)));
        int ans = dfs(0 , 0 , k , n , m , dp , grid);
        if(ans == INT_MIN) return -1;
        return ans;
    }
};