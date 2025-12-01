class Solution {
public:
    void solver(vector<vector<char>> &grid, int i,  int j ){
        if(i<0 || i>= grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0'  ) return;
        grid[i][j] = '0';
        solver(grid,i-1,j);
        solver(grid,i+1,j);
        solver(grid,i,j-1);
        solver(grid,i,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int r=grid.size(),c=grid[0].size(),ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    solver(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};