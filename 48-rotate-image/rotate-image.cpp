class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> trans(n , vector<int>(n));
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n ; j++){
                trans[j][i] = matrix[i][j];
            }
        }
        for(int i =0; i< n; i++){
            for(int j = 0; j < n/2; j++){
                swap(trans[i][j] , trans[i][n-j-1]);
            }
        }
        matrix = trans;
    }
};