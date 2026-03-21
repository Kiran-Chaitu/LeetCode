class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<int>> vis( m , vector<int>(n,0));
        queue<vector<int>> q;
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n ; j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                    vis[i][j]=1;
                }
            }
        }
        int ans = 0;
        vector<pair<int,int>> directions = { {-1 , 0} , {1,0} , {0,-1} , {0,1}};
        while(!q.empty()){
            int i = q.front()[0] , j  = q.front()[1] , time = q.front()[2];
            ans = max(ans , time);
            for(auto k : directions){
                int newRow = i+ k.first , newCol = j + k.second;
                if(newRow >=0 and newRow < m  and newCol >=0  and newCol <n and grid[newRow][newCol]==1 and !(vis[newRow][newCol])){
                    grid[newRow][newCol] = 2;
                    vis[newRow][newCol]=1;
                    q.push({newRow , newCol , time+1});
                }
            }
            q.pop();
        }
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n ; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return ans;
    }
};