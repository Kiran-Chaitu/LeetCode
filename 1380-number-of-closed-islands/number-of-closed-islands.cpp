class Solution {
public:
    void dfs(int i,int j,int n,int m, vector<vector<int>> &grid){
        if(i >= n || j >= m || i < 0 || j < 0 || grid[i][j]) return;
        grid[i][j] = 1;
        vector<vector<int>> dir = {{1,0} , {0,1} , {-1,0}, {0,-1}};
        for(auto x : dir){
            int ni = i + x[0] , nj = j + x[1];
            dfs(ni,nj,n,m,grid);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        for(int i = 0;i < n ; i++){
            dfs(i , 0, n, m, grid);
            dfs(i, m-1, n , m, grid);
        }
        for(int j = 0 ;j < m ; j++){
            dfs(0 , j , n , m ,grid);
            dfs(n-1 , j , n , m ,grid);
        }
        int ans = 0;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if(grid[i][j] == 0){
                    ans++;
                    dfs(i,j,n,m,grid);
                }
            }
        }
        return ans;

    }
};