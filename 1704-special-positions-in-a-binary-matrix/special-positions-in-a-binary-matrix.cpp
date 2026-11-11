class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans=0,rs=mat.size(),cs=mat[0].size();
        for(int i=0;i<rs;i++){
            for(int j=0;j<cs;j++){
                if(mat[i][j] == 0) continue;
                bool flag = true;
                //column
                for(int k = 0; k < rs; k++){
                    if(i!=k and mat[k][j] == 1){
                        flag = false;
                        break;
                    }
                }
                if(!flag) continue;
                for(int k = 0; k < cs ; k++){
                    if(k != j and mat[i][k]){
                        flag = false;
                        break;
                    }
                }
                if(flag) ans++;
            }
        }
        return ans;
    }
};