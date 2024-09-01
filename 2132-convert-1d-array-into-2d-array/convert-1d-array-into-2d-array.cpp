class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n > original.size() || m*n < original.size() )    return {};
        int k = original.size(),i=0;
        vector<vector<int>> v(m,vector<int>(n,0));
        for(int x=0;x<m;x++){
            for(int y=0;y<n;y++){
                v[x][y] = original[i++];
            }
        }
        return v;
    }
};