class Solution {
public:
    int solver(int i , int j, int n , vector<vector<int>> &dp , vector<vector<int>> &triangle){
        if(i == n) return triangle[i][j];
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        int left = solver(i+1,j , n , dp ,triangle) , right = solver(i+1 , j+1, n, dp , triangle);
        return dp[i][j] = triangle[i][j] + min(left , right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp;
        for(int i = 0; i < n; i++){
            vector<int> temp(triangle[i].size(), INT_MIN);
            dp.push_back(temp);
        }
        return solver(0 , 0 , n-1 , dp , triangle);
    }
};