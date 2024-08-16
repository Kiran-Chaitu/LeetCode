class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        bool up = true, down = false;
        int m = mat.size() , n = mat[0].size(),i=0,j=0;
        long long int ans = m*n;
        vector<int> v;
        while(ans){
            if(up and i>=0 and j<n){
                v.push_back(mat[i][j]);
                ans--;
                i--;
                j++;
                if(i>=0 and j>=n){
                    i+=2;
                    j=n-1;
                    up = false;
                    down = true;
                    
                }
                else if(i<0 and j<n){
                    i=0;    
                    up = false;
                    down = true;
                    
                }
                else if(i<0 and j>=n){
                    i+=2;
                    j--;
                    up = false;
                    down = true;
                    
                }
            }
            else if(down and (i>=0 and i<m) and (j>=0 and j<n) ){
                v.push_back(mat[i][j]);
                ans--;
                i++;
                j--;
                if(j<0 and i<m){
                    j=0;
                    up = true;
                    down = false;
                    
                }
                else if(i>=m and j<n){
                    j+=2;
                    i--;
                    up = true;
                    down = false;
                    
                }
                else if(i>=m and j<0){
                    i--;
                    j+=2;
                    up = true;
                    down = false;
                    
                }
            }
        }
        return v;
    }
};