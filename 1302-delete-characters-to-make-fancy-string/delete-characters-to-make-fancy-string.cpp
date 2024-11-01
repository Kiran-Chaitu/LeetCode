class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        int i=0,n=s.size();
        if(n<3) return s;
        while(i<n-1){
            int j=i,c=0;
            while(s[j] == s[j+1] and j<n){
                c++;
                j++;
            }
            if(c>0){
                ans+=s[j-1];
                ans+=s[j-1];
                j++;
                i=j;
            }
            else{
                ans+=s[j];
                i++;
            }

        }
        if(s[n-1]!=s[n-2]) ans+=s[n-1];
        return ans;
    }
};