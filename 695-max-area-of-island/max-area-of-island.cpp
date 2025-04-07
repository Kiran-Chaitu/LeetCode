class Solution {
public:
    int solver(vector<vector<int>> &nums , int n , int m , int i , int j ){
        if(i <0 || i>=n || j<0 || j>=m ||nums[i][j]==0) return 0;
        nums[i][j]=0;
        return 1 + solver(nums , n,m,i+1,j) + solver(nums,n,m,i-1,j) + solver(nums,n,m,i,j+1) + solver(nums,n,m,i,j-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans =0 , n = grid.size() , m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    ans = max(ans , solver(grid , n,m,i,j));
                }
            }
        }
        return ans;
    }
};