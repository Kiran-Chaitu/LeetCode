class Solution {
public:
    bool isValid(int i, int j ,int n,int m){
        return i>=0 and i<n and j>=0 and j<m;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size() , m = mat[0].size();
        vector<vector<int>> ans(n , vector<int>(m ,0));
        vector<vector<int>> pre(n+1 , vector<int>(m+1 ,0));
        for(int i =1;i<=n;i++){
            for(int j=1;j<=m;j++){
                pre[i][j] = mat[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
            }
        }
        for(int i=0;i<n;i++){
            for(int j = 0; j < m ; j++){
                int tli = max(0 , i -k) , tlj = max(0 , j-k);
                int bri = min(n,i+k+1) , brj = min(m,j+k+1);
                ans[i][j] = pre[bri][brj] - pre[bri][tlj] - pre[tli][brj] + pre[tli][tlj];
            }
        }
        return ans;
    }
};