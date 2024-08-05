class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        long long int row = matrix.size(),col = matrix[0].size() , ans = row*col;
        vector<int> v;
        int i=0,j=0;
        bool right = true,left = false, up = false,down=false;
        while(ans){
            //cout<<ans<<" ";
            if(right){
                while(j<col and matrix[i][j]!=-1000 and ans>0){
                    ans--;
                    v.push_back(matrix[i][j]);
                    matrix[i][j]=-1000;
                    j++;
                }
                i++;
                j--;
                down=true;
                right=false;
                
                
            }
            else if(down){
                while(i<row and matrix[i][j]!=-1000 and ans>0){
                    ans--;
                    v.push_back(matrix[i][j]);
                    matrix[i][j]=-1000;
                    i++;
                }
                j--;
                i--;
                down = false;
                left =true;
                
            }
            else if(left){
                while(j>=0 and matrix[i][j]!=-1000 and ans>0){
                    ans--;
                    v.push_back(matrix[i][j]);
                    matrix[i][j]=-1000;
                   j--;
                }
                j++;
                i--;
                up = true;
                left =false;
                
            }
            else if(up){
                while(i>0 and matrix[i][j]!=-1000 and ans>0){
                    ans--;
                    v.push_back(matrix[i][j]);
                    matrix[i][j]=-1000;
                    i--;
                }
                j++;
                i++;
                up = false;
                right =true;
                
            }
        }
        return v;
    }
};