class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
                int t = matrix[i][j];
                matrix[i][j] = matrix[i][n-j-1];
                matrix[i][n-1-j] = t;
            }
        }
    }
};