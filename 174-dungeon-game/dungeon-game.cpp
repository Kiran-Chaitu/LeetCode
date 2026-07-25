class Solution {
public:
    int solver(int i, int j, int n,int m, vector<vector<int>> &dp, vector<vector<int>> &mat){
        if(i<0 || i>=n || j<0 || j>=m) return 1e9;
        if(i == n-1 and j == m-1){
            int req = -(mat[i][j]) + 1;
            return (req <= 0) ? 1 : req;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int right = solver(i , j+1,n,m,dp , mat);
        int down = solver(i+1, j,n,m,dp , mat);
        int mini = min(right, down);
        mini = mini - (mat[i][j]);
        if(mini <= 0) mini = 1;
        return dp[i][j] = mini;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size() , m = dungeon[0].size();
        vector<vector<int>> dp(n , vector<int>(m,-1));
        return solver(0,0, n,m,dp,dungeon);
    }
};