class Solution {
public:
    int numSpecial(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size() , ans = 0;
        vector<int> row(n) , col(m);
        for(int i = 0; i  <n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == 1){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ;j++){
                if(matrix[i][j] ==0) continue;
                if(row[i]==1 and col[j] ==1) ans++;
            }
        }
        return ans;  
    }
};