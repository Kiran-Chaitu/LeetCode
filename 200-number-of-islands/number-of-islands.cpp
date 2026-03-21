class Solution {
public:
    void bfs(int i , int j ,int m ,int n,vector<vector<char>> &grid , vector<vector<int>> &vis){
        vis[i][j] = 1;
        vector<pair<int,int>> directions = { {-1,0} , { 0 , -1} , {1,0} , {0,1} };
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int r = q.front().first , c = q.front().second;
            for(auto i : directions){
                int newRow = r + i.first;
                int newCol = c + i.second;
                if(newRow >=0 and newRow < m and newCol >=0 and newCol < n and grid[newRow][newCol] == '1' and !(vis[newRow][newCol])){
                    vis[newRow][newCol] = 1;
                    q.push({newRow , newCol});
                }
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