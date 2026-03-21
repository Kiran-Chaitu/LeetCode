class Solution {
public:
    void bfs(int i , int j ,int m ,int n,vector<vector<char>> &grid , vector<vector<int>> &vis){
        vis[i][j] = 1;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int r = q.front().first , c = q.front().second;
            if(r >=0 and r <m and c+1 >=0 and c+1 < n and grid[r][c+1] == '1' and !(vis[r][c+1])){ // right
                vis[r][c+1]=1;
                q.push({r,c+1});
            }
            if(r >=0 and r <m and c-1 >=0 and c-1 < n and grid[r][c-1] == '1' and !(vis[r][c-1])){ // left
                vis[r][c-1]=1;
                q.push({r,c-1});
            }
            if(r-1 >=0 and r-1 <m and c >=0 and c < n and grid[r-1][c] == '1' and !(vis[r-1][c])){ // up
                vis[r-1][c]=1;
                q.push({r-1,c});
            }
            if(r+1 >=0 and r+1 <m and c >=0 and c < n and grid[r+1][c] == '1' and !(vis[r+1][c])){ // down
                vis[r+1][c]=1;
                q.push({r+1,c});
            }
            q.pop();
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size() , n  = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int cnt=0;
        for(int i = 0; i<m;i++){
            for(int j = 0; j < n ; j++){
                if(grid[i][j] == '1' and vis[i][j]==0){
                    bfs(i,j,m,n,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};