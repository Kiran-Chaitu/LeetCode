class Solution {
public:
    pair<int,int> solver(double step , double n){
        int i = ceil(step/n) , j = (int)step%(int)n;
        if(i&1){
            if(i == n) i =0;
            if( j == 0) return {i-1 , n-1};
            else return {i-1 , 0 + j -1};
        }
        else{
            if( j == 0) return {i-1 , 0};
            else return {i-1 , n - j};
        }
        return {-1,-1};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<vector<int>> vis(n , vector<int>(n,0));
        vis[n-1][0] = 1;
        queue<pair<int,int>> q;
        q.push({1 ,0});
        while(!q.empty()){
            pair<int,int> node = q.front();
            double step = node.first , moves = node.second;
            pair<int,int> indices = solver(step , n);
            int i = indices.first, j = indices.second;
            for(int k = 1 ; k <= min( 6, n*n - (int)step) ; k++ ){
                pair<int,int> newIndices = solver(step + k , n);
                i = n - 1 - newIndices.first , j = newIndices.second;
                cout<<(step+k)<<" "<<i<<" "<<j<<" "<<moves+1<<endl;
                if(step+k == n * n) return moves+1;
                if(i == n || i < 0 ) i=0;
                if(!vis[i][j] and board[i][j] == -1){
                    cout<<"step :- "<<(step+k)<<" "<<i<<" "<<j<<" "<<moves+1<<endl;
                    if(step+k == n * n) return moves+1;
                    q.push({step + k , moves + 1});
                }
                else if(!vis[i][j] and board[i][j]!=-1){
                    pair<int,int> temp = solver(board[i][j] , n);
                    int x = n - 1 - temp.first , y = temp.second;
                    if(x == n || x < 0) x=0;
                    // vis[x][y] = 1;
                    cout<<"Ladder or Snake:- "<<board[i][j]<<" "<<x<<" "<<y<<" "<<moves+1<<endl;
                    if(board[i][j] == n*n) return moves+1;
                    q.push({board[i][j] , moves+1});
                }
                vis[i][j]=1;
            }
            q.pop();
        }
        return -1;
    }
};