class Solution {
public:
    bool isValid(int i,int j,int n){
        if(i < 0 || j < 0 || i>=n || j>=n ){
            return false;
        }
        return true;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int ans = INT_MIN;
        int n = grid.size();
        vector<vector<int>> vis(n , vector<int>(n));
        vis[0][0]=1;
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        pq.push({grid[0][0],0,0});
        vector<vector<int>> directions = {{0,-1} , {0,1} , {1,0} , {-1,0}};
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int node = temp[0] , i = temp[1] , j = temp[2];
            ans = max(ans , node);
            if(i == n-1 and j == n-1) return ans;
            for(auto it: directions){
                int r = i + it[0] , c = j + it[1];
                if(isValid(r,c,n) and !(vis[r][c])){
                    vis[r][c] = 1;
                    pq.push({grid[r][c] , r,c});
                }
            }
        }
        return -1;

    }
};