class Solution {
public:
    void dfs(vector<vector<char>> &board , vector<vector<int>> &vis, int i  ,  int j , int n, int m){
        if(i >=n || j>=m|| i< 0  || j < 0 || vis[i][j]) return;
        vis[i][j] = 1;
        dfs(board , vis , i+1 , j , n ,m);
        dfs(board , vis , i-1 , j , n ,m);
        dfs(board , vis , i , j+1 , n ,m);
        dfs(board , vis , i , j-1 , n ,m);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size() , m= board[0].size();
        vector<vector<int>> vis(n , vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) if(board[i][j] == 'X') vis[i][j]=1;
        }
        
        for(int i=0;i<n;i++){
            for(int j = 0 ;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) and (!vis[i][j])) dfs(board , vis , i , j , n , m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j = 0; j<m;j++){
                if(!vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};