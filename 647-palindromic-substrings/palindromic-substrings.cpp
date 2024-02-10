class Solution {
public:
    bool ispal(string s,int l , int r){
        while(l<=r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int c=0,n=s.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ispal(s,i,j)) c++;
            }
        }
        return c;
    }
};