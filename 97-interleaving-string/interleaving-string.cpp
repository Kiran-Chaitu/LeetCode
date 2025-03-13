class Solution {
public:
    bool solver(int a,int b ,int c,int i,int j,int k, string &s1,string &s2,string &s3,vector<vector<int>> &dp){
        if(i==a and j==b) return dp[i][j]=1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==a){
            if(s2[j]==s3[k]) return dp[i][j] =  solver(a,b,c,i,j+1,k+1 , s1,s2,s3,dp);
            return dp[i][j]=0;
        }
        if(j==b){
            if(s1[i]==s3[k])    return dp[i][j] = solver(a,b,c,i+1,j,k+1,s1,s2,s3,dp);
            return dp[i][j]=0;
        }
        if((s1[i] == s3[k]) and (s2[j]==s3[k]) )
         return dp[i][j] =  solver(a,b,c,i+1,j,k+1,s1,s2,s3,dp) || solver(a,b,c,i,j+1,k+1,s1,s2,s3,dp);
        if(s1[i]==s3[k])  return dp[i][j] =  solver(a,b,c,i+1,j,k+1,s1,s2,s3,dp);
        if(s2[j]==s3[k]) return dp[i][j] =  solver(a,b,c,i,j+1,k+1,s1,s2,s3,dp);
        return dp[i][j] = 0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int a = s1.size() ,  b = s2.size() , c = s3.size();
        if(a+b !=c) return false;
        vector<vector<int>> dp(a+1 , vector<int>(b+1,-1));
        return (solver(a,b,c,0,0,0,s1,s2,s3 ,dp) == 1) ? true : false;
    }
};