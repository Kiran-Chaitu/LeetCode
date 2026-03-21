class Solution {
public:
    void dfs(int i , int j ,int m ,int n,vector<vector<char>> &grid , vector<vector<int>> &vis){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j]=='0' || vis[i][j]) return;
        vis[i][j] = 1;
        dfs(i+1 , j ,m, n , grid , vis); // down
        dfs(i-1 , j ,m, n , grid , vis); //up
        dfs(i , j+1 ,m, n , grid , vis); // right
        dfs(i , j-1 ,m, n , grid , vis); //left
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size() , n  = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int cnt=0;
        for(int i = 0; i<m;i++){
            for(int j = 0; j < n ; j++){
                if(grid[i][j] == '1' and vis[i][j]==0){
                    dfs(i,j,m,n,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};