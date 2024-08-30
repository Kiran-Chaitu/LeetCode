class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string rev ="";
        for(int i=s.size()-1;i>=0;i--) rev+=s[i];
        int n=s.size();
        vector<vector<int>> v(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n+1;i++){
            v[0][i]=0;
            v[i][0]=0;
        }
        for(int i=1;i<v.size();i++){
            for(int j=1;j<v[0].size();j++){
                if(s[i-1]==rev[j-1]){
                    v[i][j]=(1 + v[i-1][j-1]);
                }
                else{
                    v[i][j] = max(v[i-1][j],v[i][j-1]);
                }
            }
        }
        return v[n][n];
    }
};