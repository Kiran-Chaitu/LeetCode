class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size() ,  m= mat[0].size();
        vector<vector<int>>  vis(n , vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!mat[i][j]){
                    q.push({i , j});
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            int i = q.front().first , j = q.front().second;
            q.pop();
            if(i+1 <  n and !vis[i+1][j]){
                q.push({i+1,j});
                vis[i+1][j]=1;
                mat[i+1][j] += mat[i][j];
            }
            if(i-1 >=0 and !vis[i-1][j]){
                q.push({i-1,j});
                vis[i-1][j]  =1;
                mat[i-1][j] += mat[i][j];
            }
            if(j+1 < m and !vis[i][j+1]){
                q.push({i , j+1});
                vis[i][j+1] = 1;
                mat[i][j+1] += mat[i][j];

            }
            if(j-1 >=0 and !vis[i][j-1]){
                q.push({i , j-1});
                vis[i][j-1] =1;
                mat[i][j-1] += mat[i][j];
            }
        }
        return mat;
    }
};