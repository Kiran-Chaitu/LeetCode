class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size() , m = isWater[0].size();
        vector<vector<int>> ans(n , vector<int>(m , 0)) , vis(n, vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(isWater[i][j]){
                    q.push({ i ,j});
                    vis[i][j] = 1;
                    ans[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int i = q.front().first , j = q.front().second;
            q.pop();
            if(i-1 >=0 and !vis[i-1][j]){
                vis[i-1][j] = 1;
                q.push({i-1,j});
                ans[i-1][j] += ans[i][j] +1;
            }
            if(i+1 < n and !vis[i+1][j]){
                vis[i+1][j] = 1;
                q.push({i+1, j});
                ans[i+1][j] += ans[i][j] + 1;
            }
            if(j-1 >=0 and !vis[i][j-1]){
                vis[i][j-1] =1;
                q.push({i , j-1});
                ans[i][j-1] += ans[i][j] +1;
            }
            if(j+1 < m and !vis[i][j+1]){
                vis[i][j+1] = 1;
                q.push({i , j+1});
                ans[i][j+1] += ans[i][j] + 1;
            }
        }
        return ans;
    }
};