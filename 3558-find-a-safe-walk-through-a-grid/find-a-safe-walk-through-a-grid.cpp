class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m,INT_MAX));
        dist[0][0] = grid[0][0];
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        pq.push({dist[0][0], 0,0});
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int val = node[0] , i = node[1] , j = node[2];
            if(val  > dist[i][j]) continue;
            vector<vector<int>> dir = {{-1,0} , {1,0} , {0,-1} , {0,1}};
            for(auto x : dir){
                int ni = i + x[0] , nj = j + x[1];
                if(ni >=0  and nj >=0 and ni<n and nj <m ){
                    int nv = val + grid[ni][nj];
                    if(nv < dist[ni][nj]){
                        dist[ni][nj] = nv;
                        pq.push({nv , ni , nj});
                    }
                }
            }
        }
        return health > dist[n-1][m-1];
    }
};