class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size() , n = matrix[0].size();
        vector<int> ans;
        for(int i = 0; i < m;i++){
            int mini = INT_MAX;
            int col = -1;
            for(int j = 0; j < n ; j++){
                if(mini > matrix[i][j]){
                    mini = matrix[i][j];
                    col = j;
                }
            }
            bool flag = true;
            for(int k = 0 ; k< m; k++ ){
                if(mini < matrix[k][col]){
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(matrix[i][col]);
        }
        return ans;

    }
};