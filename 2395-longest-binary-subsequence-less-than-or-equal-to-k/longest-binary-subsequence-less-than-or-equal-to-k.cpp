class Solution {
public:
    int longestSubsequence(string s, int k) {
        long long c =0 , c1=0 ;
        for(auto i:s) if(i=='1') c1++; else c++;
        if(c1==0) return c;
        long long  l=0 ,j=0 , len=0;
        for(int i=s.size()-1;i>=0 and l<k ;i--,j++ ){
            if(s[i]=='1'){
                if(j>=32) break;
                l+= (long long)(1LL<<j);
                if(l==k) return c+j+1;
                else if(l>k){
                    break;
                }
            }else c--;
            len++;
        }
        return c + len;
    }
};