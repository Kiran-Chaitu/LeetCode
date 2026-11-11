class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n  = matrix.size() , m = matrix[0].size();
        for(int i = 0; i < n;i++){
            int mini = INT_MAX , col =-1;
            for(int j = 0; j < m ; j++){
                if(mini > matrix[i][j]){
                    mini = matrix[i][j];
                    col = j;
                }
            }
            bool lucky = true;
            for(int k = 0 ; k < n ; k++){
                if(mini < matrix[k][col]){
                    lucky = false;
                    break;
                }
            }
            if(lucky){
                ans.push_back(mini);
                break;
            }
        }
        return ans;
    }
};