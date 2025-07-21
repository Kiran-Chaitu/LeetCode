class Solution {
public:
    void dfs(vector<vector<int>> &grid , int i , int j , int n , int m , vector<vector<int>> &vis){
        if(i < 0 || j<0 || j>=m || i>=n || vis[i][j]) return;
        if((grid[i][j])) grid[i][j] = 0;
        vis[i][j] = 1;
        dfs(grid , i +1 , j , n , m , vis); 
        dfs(grid , i -1 , j , n , m , vis);
        dfs(grid , i  , j+1 , n , m , vis);
        dfs(grid , i  , j-1 , n , m , vis);
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> vis(n,  vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) if(grid[i][j] == 0) vis[i][j] = 1;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j = 0 ;j < m ;j++){
                if((i==0 || i == n-1 || j==0 || j== m-1) and !vis[i][j]) dfs(grid, i , j , n , m , vis);
            }
        }
        for(int i=0;i<n;i++){
            for(int j = 0 ;j < m;j++) if(grid[i][j]) ans++;
        }
        return ans;
    }
};