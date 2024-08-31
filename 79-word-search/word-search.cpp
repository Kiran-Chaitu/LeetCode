class Solution {
public:
    bool ans=false;
    void solver(vector<vector<char>> &board, int i,int j,int r,int c,int x, string word,vector<vector<int>> &vis){
        if(i<0 || i>=r || j<0 || j>=c || vis[i][j]==1 || board[i][j]!=word[x] ) return;
        if(x>=word.size()-1){
            ans=true;
            return;
        }
        vis[i][j]=1;
        solver(board,i-1,j,r,c,x+1,word,vis);
        solver(board,i+1,j,r,c,x+1,word,vis);
        solver(board,i,j-1,r,c,x+1,word,vis);
        solver(board,i,j+1,r,c,x+1,word,vis);
        vis[i][j]=0;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size(),c=board[0].size();
        vector<vector<int>> vis(r,vector<int> (c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]==word[0]){
                    solver(board,i,j,r,c,0,word,vis);
                    if(ans) return true;
                }
            }
        }
        return false;
    }
};