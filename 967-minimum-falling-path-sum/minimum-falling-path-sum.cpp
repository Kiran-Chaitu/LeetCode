class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==0 and j+1<n){
                    matrix[i][j]+=min(matrix[i-1][j] , matrix[i-1][j+1]);
                }
                else if(n>1 and j==n-1){
                    matrix[i][j]+=min(matrix[i-1][j] , matrix[i-1][j-1]);
                }
                else{
                    matrix[i][j]+=min(matrix[i-1][j] , min(matrix[i-1][j-1] , matrix[i-1][j+1]));
                }
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++) mini = min(matrix[n-1][i] , mini);
        return mini;
    }
};