class Solution {
public:
    bool ans = false;
    void solver(vector<vector<char>> &board , string &word , int i , int j , int ind ,vector<vector<int>> &vis , int n , int m , int len){
        if(i<0 || i >= n ||j<0 || j>=m || vis[i][j] || board[i][j] != word[ind] ) return;
        if(ind == len-1 and board[i][j] == word[ind]){ 
            ans = true;
            return;
        }
        vis[i][j] = 1;
        solver(board , word , i+1 , j , ind+1 , vis,n,m,len);
        solver(board , word , i-1 , j , ind+1 , vis,n,m,len);
        solver(board , word , i , j+1 , ind +1 , vis,n,m,len);
        solver(board , word , i , j-1 ,ind +1 , vis,n,m,len);
        vis[i][j] =0;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int len = word.size(), n = board.size() , m = board[0].size();
        vector<vector<int>> vis(n , vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    solver(board , word , i , j ,0 , vis , n , m ,len);
                    if(ans){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};