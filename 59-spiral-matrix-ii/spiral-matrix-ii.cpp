class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n,vector(n,0));
        int i=0,j=0,ans=1;
        bool right=true,down=false,left=false,up=false,flag=true;
        while(flag){
            if(right){
                while(j<n and v[i][j]==0){
                    v[i][j++] = ans++;
                }
                j--;
                i++;
                right=false;
                down=true;
                if(i>=n or j>=n or i<0 or j<0 or v[i][j]!=0) flag=false;
            }
            else if(down){
                while(i<n and v[i][j]==0) {
                    v[i++][j]=ans++;
                }
                i--;
                j--;
                down = false;
                left=true;
                if(i>=n or j>=n or i<0 or j<0 or v[i][j]!=0) flag=false;
            }
            else if(left){
                while(j>-1 and v[i][j]==0){
                    v[i][j--] = ans++;
                }
                j++;
                i--;
                left=false;
                up = true;
                if(i>=n or j>=n or i<0 or j<0 or v[i][j]!=0) flag=false;
            }
            else if(up){
                while(i>0 and v[i][j]==0){
                    v[i--][j] = ans++;
                }
                i++;
                j++;
                up = false;
                right= true;
                if(i>=n or j>=n or i<0 or j<0 or v[i][j]!=0) flag=false;
            }

        }
        return v;
    }
};