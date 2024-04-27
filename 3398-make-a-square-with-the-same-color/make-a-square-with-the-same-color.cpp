class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int wc=0,bc=0;
        for(int i=0;i<=1;i++){
            for(int j=0;j<=1;j++){
                if(grid[i][j]=='B') bc++;
                else wc++;
            }
        }
        if(wc==bc){
            wc=0,bc=0;
        }
        else return true;
        for(int i=0;i<2;i++){
            for(int j=1;j<=2;j++){
                if(grid[i][j]=='B') bc++;
                else wc++;
            }
        }
        if(wc==bc){
            wc=0,bc=0;
        }
        else return true;
        for(int i=1;i<=2;i++){
            for(int j=0;j<=1;j++){
                if(grid[i][j]=='B') bc++;
                else wc++;
            }
        }
        if(wc==bc){
            wc=0,bc=0;
        }
        else return true;
        for(int i=1;i<=2;i++){
            for(int j=1;j<=2;j++){
                if(grid[i][j]=='B') bc++;
                else wc++;
            }
        }
        if(wc==bc){
            return false;
        }
        else return true;
    }
};