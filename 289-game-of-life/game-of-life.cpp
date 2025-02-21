class Solution {
public:
    int checkNeighbours(int i , int j , int n , int m , vector<vector<int>> &board){
        int c=0;
        if(i-1>=0){
            if(j-1 >=0 and board[i-1][j-1] )    c++;
            if(board[i-1][j]) c++;
            if(j+1<m and board[i-1][j+1]) c++;
        }
        if(j-1>=0 and board[i][j-1]) c++;
        if(j+1<m and board[i][j+1])   c++;
        if(i+1 < n ){
            if(j-1>=0 and board[i+1][j-1]) c++;
            if(board[i+1][j]) c++;
            if(j+1 < m and board[i+1][j + 1]) c++;
        }
        return c;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size() , m = board[0].size();
        vector<vector<int>>  v(n , vector<int>( m , 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==1){
                    int k = checkNeighbours(i , j , n , m ,board);
                    if(k==2 || k==3) v[i][j]=1;
                }
                else{
                    if(checkNeighbours(i  , j  ,n , m, board) == 3){
                        v[i][j] = 1;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j] = v[i][j];
            }
        }
    }
};