class Solution {
public:
    int numSpecial(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size() , ans = 0;
        for(int i = 0; i  <n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == 0) continue;
                bool special = true;
                //row
                for(int k = 0 ; k < m ; k++){
                    if(k != j and matrix[i][k] == 1){
                        special = false;
                        break;
                    }
                }
                if(special == false) continue;
                //column
                for(int k = 0; k < n ; k++){
                    if(k != i and matrix[k][j] == 1){
                        special = false;
                        break;
                    }
                }
                if(special) ans++;
            }
        }
        return ans;  
    }
};