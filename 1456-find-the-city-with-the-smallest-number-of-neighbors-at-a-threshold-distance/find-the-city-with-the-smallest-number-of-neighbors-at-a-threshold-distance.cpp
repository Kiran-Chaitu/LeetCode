class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n , vector<int>(n,1e9));
        for(int i =0;i<n;i++){
            mat[i][i] = 0;
        }
        for(auto i : edges){
            mat[i[0]][i[1]] = i[2];
            mat[i[1]][i[0]] = i[2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(mat[i][k]==1e9 || mat[k][j] == 1e9) continue;
                    mat[i][j] = min(mat[i][j] , mat[i][k] + mat[k][j]);
                }
            }
        }
        int ansCity = -1 , count =n;
        for(int i =0;i<n;i++){
            int c=0;
            for(int j =0;j<n;j++){
                if(mat[i][j] <= distanceThreshold){
                    c++;
                }
            }
            if(c <= count){
                ansCity = i;
                count =c;
            }
        }
        return ansCity;
    }
};