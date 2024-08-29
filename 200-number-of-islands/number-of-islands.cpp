class Solution {
public:
    void solver(vector<vector<char>> &grid, int i,  int j,vector<vector<int>> &check ){
        if(i<0 || i>= grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0' || check[i][j]==1 ) return;
        check[i][j]=1;
        solver(grid,i-1,j,check);
        solver(grid,i+1,j,check);
        solver(grid,i,j-1,check);
        solver(grid,i,j+1,check);
    }
    int numIslands(vector<vector<char>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int r=grid.size(),c=grid[0].size(),ans=0;
        vector<vector<int>> check(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1' and check[i][j]==0){
                    solver(grid,i,j,check);
                    ans++;
                }
            }
        }
        return ans;
    }
};