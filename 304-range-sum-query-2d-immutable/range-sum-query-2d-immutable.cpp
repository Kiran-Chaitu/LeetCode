class NumMatrix {
public:
vector<vector<int>> pre;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        pre.resize(n+1 , vector<int>(m+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                pre[i][j] = matrix[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
            }
        }
        // for(auto i : pre){
        //     for(auto j : i) cout<<j<<" ";
        //     cout<<endl;
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++ , col1++ , row2++ , col2++;
        return pre[row2][col2] - pre[row1-1][col2] - pre[row2][col1-1] 
        + pre[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */