class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();
        bool up = true;
        int ans = n * m , i = 0, j =0;
        vector<int> v;
        while(ans--){
            v.push_back(mat[i][j]);
            if(up == true){
                if(j == m-1){
                    i++;
                    up = false;
                }else if(i == 0){
                    j++;
                    up = false;
                }else{
                    i--;
                    j++;
                }

            }else{
                if(i == n-1){
                    j++;
                    up = true;
                }else if(j == 0){
                    i++;
                    up = true;
                }else{
                    i++;
                    j--;
                }
            }
        }
        return v;
    }
};