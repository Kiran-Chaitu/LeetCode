class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        vector<vector<int>> ans(m , vector<int>(n));
        for(int j = 0; j < m; j++){
            // vector<int> temp;
            for(int i = 0; i < n ; i++){
                // temp.push_back(matrix[i][j]);
                ans[j][i] = matrix[i][j];
            }
            // ans.push_back(temp);
        }
        return ans;
    }
};