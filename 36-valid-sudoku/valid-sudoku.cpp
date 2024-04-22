class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<9;i++){
            unordered_map<char,int> r,c;
            for(int j=0;j<9;j++){
                if(board[i][j] != '.') r[board[i][j]]++;
                if(board[j][i] != '.') c[board[j][i]]++;
                if(r[board[i][j]] > 1 or c[board[j][i]] > 1){
                    // cout<<board[i][j]<<" - "<<r[board[i][j]]<<endl<<board[j][i]<<" - "<<c[board[j][i]]<<endl;
                    // cout<<i<<" "<<j;
                    return false;
                } 
            }
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                unordered_map<char,int> r;
                for(int x=i;x<i+3;x++){
                    for(int y=j;y<j+3;y++){
                        if(board[x][y] != '.')  r[board[x][y]]++;
                        if(r[board[x][y]] > 1) return false;
                    }
                }
            }
        }
         
        return true;
    }
};