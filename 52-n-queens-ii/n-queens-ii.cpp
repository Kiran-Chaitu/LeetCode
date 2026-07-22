class Solution {
public:
    set<vector<string>> ans;
    void solver(int n,int col, vector<string> &board , vector<int> &ld , vector<int> &rd , vector<int> &row){
        if(col >= n){
            ans.insert(board);
            return;
        }
        for(int i = 0; i < n ; i++){
            if(ld[i - col + n-1] == 0 and rd[i+col] == 0 and row[i] == 0){
                board[i][col] = 'Q';
                ld[i-col + n-1] = 1;
                rd[i+col] = 1;
                row[i] = 1;
                solver(n , col+1 , board , ld,rd,row);
                board[i][col]= '.';
                ld[i-col+n-1] = 0; 
                rd[i+col] = 0;
                row[i] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<int> ld(2*n-1) , rd(2*n-1) , row(2*n-1);
        vector<string> board;
        for(int i = 0; i< n ; i++){
            string s = "";
            for(int j = 0; j < n ; j++){
                s+='.';
            }
            board.push_back(s);
        }
        solver( n , 0 ,board, ld, rd , row);
        return ans.size();
    }
};