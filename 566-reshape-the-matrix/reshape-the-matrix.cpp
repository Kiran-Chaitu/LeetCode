class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(mat.size() * mat[0].size() != r*c) return mat;
        vector<vector<int>> ans(r , vector<int>(c));
        int nr = 0 , nc = 0;
        for(int i =0 ; i< mat.size(); i++){
            for(int j = 0; j < mat[0].size();j++){
                cout<<nr<<" "<<nc<<endl;
                if(nc < c){
                    ans[nr][nc] = mat[i][j];
                }else{
                    nc = 0;
                    nr++;
                    ans[nr][nc] = mat[i][j];
                }
                nc++;
            }
        }
        return ans;
    }
};