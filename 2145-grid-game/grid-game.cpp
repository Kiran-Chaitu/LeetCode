class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long fSum=0,sSum=0, n = grid[0].size(),mini=LLONG_MAX;
        for(int i=0;i<n;i++){
            fSum += grid[0][i];
        }
        for(int i=0;i<n;i++){
            fSum -= grid[0][i];
            mini = min(mini , max(fSum , sSum));
            sSum+=grid[1][i];
        }
        return mini;
    }
};