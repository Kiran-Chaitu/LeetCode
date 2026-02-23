class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() , ans = 0;
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<int>> dir = { {-1,-1} , {-1,0} , {-1 , +1} , {0,-1} , { 0 , +1} , {+1,-1} , {+1 , 0} , {+1,+1}};
        while(!q.empty()){
            int k = q.size();
            for(int x = 0; x < k; x++){
                auto node  = q.front();
                int i = node.first , j = node.second;
                if(i == n-1 and j==n-1) return ans+1;
                for(auto y : dir){
                    int nr = i + y[0] , nc = j+ y[1];
                    if(nr >= 0 and nr < n and nc >=0 and nc < n and grid[nr][nc] == 0){
                        grid[nr][nc] = 1;
                        q.push({nr,nc});
                    }
                }
                q.pop();
            }
            ans++;
        }
        return -1;
    }
};