class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        int i,j;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    if(j==m-1 || (j<m-1 && grid[i][j+1]==0))
                    {
                        ans++;
                    }
                    if(j==0 || (j>0 && grid[i][j-1]==0))
                    {
                        ans++;
                    }
                    if(i==0 || (i>0 && grid[i-1][j]==0))
                    {
                        ans++;
                    }
                    if(i==n-1 || (i<n-1 && grid[i+1][j]==0))
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};