class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int n  = mat.size() , m = mat[0].size();
        unordered_map<int,int> mp;
        unordered_map<int,int> rows,cols;
        unordered_map<int,pair<int,int>> row_col;
        vector<int> ans;
        for(int i=0;i<arr.size();i++) mp[arr[i]]=i;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                row_col[mat[i][j]] = {i,j};
            }
        }
        for(int i=0;i<arr.size();i++){
            rows[row_col[arr[i]].first]++;
            cols[row_col[arr[i]].second]++;
            if(rows[row_col[arr[i]].first] == m || cols[row_col[arr[i]].second] == n) return i;
        }
        return -1;
    }
};