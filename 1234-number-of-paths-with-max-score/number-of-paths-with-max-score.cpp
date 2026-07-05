class Solution {
public:
    int mod = 1e9+7;
    pair<int,int> solver(int i,int j ,vector<vector<pair<int,int>>> &dp,vector<string> &board){
        if(i < 0 || j < 0 || board[i][j] == 'X') return {-1,0};
        if(i == 0 and j == 0) return {0,1};
        if(dp[i][j].first !=-2) return dp[i][j];
        auto left = solver(i , j-1 , dp ,board);
        auto up = solver(i-1,j,dp , board);
        auto daig = solver(i-1 , j-1 , dp , board);
        int maxi = max(left.first , max(up.first , daig.first));
        if(maxi == -1) return dp[i][j] = {-1,0};
        long long w = 0;
        if(left.first == maxi) w+=(left.second);
        if(up.first == maxi) w+=(up.second);
        if(daig.first ==maxi) w+=(daig.second);
        w%=mod;
        int temp =0;
        if(board[i][j]>='0' and board[i][j]<='9') temp += board[i][j] - '0';
        return dp[i][j] = {maxi + temp , w}; 
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<pair<int,int>>> dp(n , vector<pair<int,int>>(n , {-2,-2}));
        auto ans = solver(n-1,n-1 , dp , board);
        if(ans.first == -1) return {0,0};
        return {ans.first, ans.second};
    }
};