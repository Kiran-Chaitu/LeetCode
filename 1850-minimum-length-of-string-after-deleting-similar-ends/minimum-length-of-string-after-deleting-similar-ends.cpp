class Solution {
public:
    int minimumLength(string s) {
        ios_base::sync_with_stdio(0);
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]==s[j]){
                while(s[i]==s[i+1] and i<j) i++;
                while(s[j-1]==s[j] and i < j) j--;
                i++;
                j--;
            }
            else break;
        }
        int c=j-i+1;
        if(c<0) return 0;
        return c;
    }
};