class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int,int> row,col;
        for(int i=0;i<grid.size();i++){
            int sum=0;
            for(int j=0;j<grid[0].size();j++){
                sum+=grid[i][j];
            }
            row[i]=sum;
        }
        for(int j=0;j<grid[0].size();j++){
            int sum=0;
            for(int i=0;i<grid.size();i++){
                sum+=grid[i][j];
            }
            col[j]=sum;
        }
        int c=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if((row[i] > 1 or col[j]>1) and grid[i][j]==1 ) c++;
            }
        }
        return c;
    }
};