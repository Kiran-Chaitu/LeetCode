class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(0);
        unordered_map<int,int> row,col;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }    
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(row.find(i)!=row.end() || col.find(j)!=col.end()) matrix[i][j]=0;
            }
        }
    }
};