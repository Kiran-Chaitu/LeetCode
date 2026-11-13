class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> arr(n, vector<int>(m));
        int temp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int k = n-i-1;
                temp = matrix[i][j];
                arr[j][k] = temp;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                matrix[i][j] = arr[i][j];
            }
        }

    }
};