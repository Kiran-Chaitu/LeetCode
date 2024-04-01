class Solution {
public:
    int lengthOfLastWord(string s) {
        ios_base::sync_with_stdio(0);
        int k=s.size()-1,c=0;
        while(s[k]==' ') k--;
        while(s[k--]!=' '){
            c++;
            if(k<0) break;   
        }  
        return c;
    }
};